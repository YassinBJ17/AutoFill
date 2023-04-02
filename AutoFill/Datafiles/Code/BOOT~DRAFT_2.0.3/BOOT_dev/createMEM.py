import argparse
import configparser
import hashlib
import struct
from collections import OrderedDict

KeyValFormat = '>2I'

CRC32_POLYNOMIAL = 0x82608EDB

# python binary operations do not carry so doing that manually
poly = CRC32_POLYNOMIAL << 1
if CRC32_POLYNOMIAL & 0x80000000:
    poly += 1

def crc32(data, crc):
    for i in range(32):
        if ((crc >> 31) & 0x1) ^ ((data >> i) & 0x1):
            crc = (crc << 1) ^ poly
        else:
            crc = crc << 1
        crc = crc & 0xFFFFFFFF
    return crc

class MultiOrderedDict(OrderedDict):
    def __setitem__(self, key, value):
        if isinstance(value,list) and key in self:
            i = 0
            key = key + '#' + str(i)
            while key in self:
                i += 1
                key = key + '#' + str(i)
        super().__setitem__(key, value)

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Create a MEM (NVM mapping) File',
                                    fromfile_prefix_chars='@')

    parser.add_argument('-b', '--binary', type=argparse.FileType('wb'), help='Output MEM file as binary')
    parser.add_argument('-o', '--output', type=argparse.FileType('w'), help='Output MEM file as text')
    parser.add_argument('-q', '--quiet', action='store_true', help='Do not output extra info')

    parser.add_argument('-p', '--lpn', type=str, help='The Load part number', default='')

    parser.add_argument('config', type=argparse.FileType('r'), help='Config file with LOADs details')

    try:
        args = parser.parse_args()

        config = configparser.ConfigParser(dict_type=MultiOrderedDict, strict=False, inline_comment_prefixes=('#', ';', '//'), defaults={'load_pn':args.lpn}, interpolation=configparser.ExtendedInterpolation())

        config.read_file(args.config)

        selected = ''
        zones = {}
        total_size = int(config.get('DEFAULT', 'size', fallback=str(0)), 0)

        for section in config.sections():
            try:
                typ = config.get(section, 'type')
                if selected == '':
                    raise Exception('No zone declared before {}'.format(section))
                if typ == 'values':
                    if not args.quiet:
                        print("Encode '{}' values in zone '{}' as key/value file".format(section, selected))
                    for k,v in config.items(section):
                        try:
                            addr = int(k.split('#', 1)[0], 0)
                            dat = int(v, 0)
                            zones[selected]['data'] += struct.pack(KeyValFormat, addr, dat)
                            zones[selected]['crc'] = crc32(addr, zones[selected]['crc'])
                            zones[selected]['crc'] = crc32(dat, zones[selected]['crc'])
                        except:
                            pass
                    zones[selected]['last'] = addr
                elif typ == 'binary':
                    addr = int(config.get(section, 'dst_addr', fallback=str(zones[selected]['last'])), 0)
                    if addr < 0:
                        addr = zones[selected]['last']
                    name = config.get(section, 'name', fallback=section)
                    path = config.get(section, 'path')
                    if not args.quiet:
                        print("Encode '{}' in zone '{}' at @ 0x{:04x} (in bytes: 0x{:04x})".format(section, selected, addr, addr * 4))
                    with open(path + '/' + name, 'rb') as file:
                        data = file.read(4)
                        while len(data) > 0:
                            dat = 0
                            for i in range(len(data)):
                                dat <<= 8
                                dat += int(data[i])
                            zones[selected]['data'] += struct.pack(KeyValFormat, addr, dat)
                            zones[selected]['crc'] = crc32(addr, zones[selected]['crc'])
                            zones[selected]['crc'] = crc32(dat, zones[selected]['crc'])
                            addr += 1
                            data = file.read(4)
                    zones[selected]['last'] = addr
                else:
                    raise Exception("Unknown section type '{}' in zone '{}'".format(section, selected))
            except configparser.NoOptionError as err:
                selected = section
                addr = int(config.get(section, 'envm_addr'), 0)
                if addr > total_size:
                    total_size = addr
                zones[selected] = {'addr': addr * 4, 'crc': 0xFFFFFFFF, 'crc_enabled': config.getboolean(section, 'crc'), 'footer_enabled': config.getboolean(section, 'footer'), 'last':0,  'data': b''}
            except FileNotFoundError as err:
                print(err)
                exit(1)

        buff = bytearray(b'\xFF' * (total_size * 4))

        for zone in zones:
            zones[zone]['crc'] = zones[zone]['crc'] ^ 0xFFFFFFFF
            if len(zones[zone]['data']) > 0:
                if zones[zone]['crc_enabled']:
                    if not args.quiet:
                        print('Zone[{}] CRC: {:08X}'.format(zone, zones[zone]['crc']))
                    zones[zone]['data'] = struct.pack(KeyValFormat, 0, zones[zone]['crc']) + zones[zone]['data']
                if zones[zone]['footer_enabled']:
                    zones[zone]['data'] += struct.pack(KeyValFormat, 0xFFFFFFFF, 0xFFFFFFFF)
                buff[zones[zone]['addr']:zones[zone]['addr']+len(zones[zone]['data'])] = zones[zone]['data']
        
        if args.binary != None:
            args.binary.write(buff)

        if args.output != None:
            count = 0
            for b in buff:
                args.output.write('{:08b}'.format(b))
                count += 1
                if not count % 4:
                    args.output.write('\n')

        print('Script md5: {}'.format(hashlib.md5(open(__file__, 'rb').read()).hexdigest()))

    except AttributeError as err:
        print(err)
        parser.print_help()
