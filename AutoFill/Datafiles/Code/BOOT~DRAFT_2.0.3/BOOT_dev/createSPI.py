import argparse
import configparser
import hashlib
import struct
from collections import OrderedDict

# Configuration file defined in NXP AN3659, here using EEPROM SPI flavor

HeaderFormat = '>64x4s4xI4xI4xI4xI4xI20x'
KeyValFormat = '>2I'
FooterFormat = '>I'

HeaderSignature = b'BOOT'
FooterSignature = 0xefefefef

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

    parser = argparse.ArgumentParser(description='Create a LUD (Flash Descriptor) File',
                                    fromfile_prefix_chars='@')

    parser.add_argument('-o', '--output', type=argparse.FileType('wb'), help='Output LUD file')

    parser.add_argument('config', type=argparse.FileType('r'), help='Config file with LOADs details')

    try:
        args = parser.parse_args()

        config = configparser.ConfigParser(dict_type=MultiOrderedDict, strict=False, inline_comment_prefixes=('#', ';', '//'))

        config.read_file(args.config)

        keyvals = bytes()
        count = 1

        if config.has_section('keyvals'):
            for k,v in config.items('keyvals'):
                try:
                    key = int(k.split('#', 1)[0], 0)
                    val = int(v, 0)
                    keyvals += struct.pack(KeyValFormat, key, val)
                    count += 1
                except:
                    pass

        realsize = struct.calcsize(HeaderFormat) + len(keyvals) + struct.calcsize(FooterFormat)

        size = int(config.get('DEFAULT', 'size', fallback=str(realsize)), 0)
        src_addr = int(config.get('DEFAULT', 'src_addr', fallback=str(size)), 0)
        dst_addr = int(config.get('DEFAULT', 'dst_addr', fallback=0), 0)
        length = int(config.get('DEFAULT', 'length', fallback=0), 0)
        delta = int(config.get('DEFAULT', 'delta', fallback=0), 0)

        pack = struct.pack( HeaderFormat, 
                            HeaderSignature,
                            length,
                            src_addr,
                            dst_addr,
                            dst_addr + delta,
                            count)

        pack += keyvals

        pack += struct.pack(FooterFormat, FooterSignature)

        pad = size - len(pack)
        if pad > 0:
            pack += bytearray(pad)

        if args.output == None:
            output = open('spi.bin', 'wb')
        else:
            output = args.output
        output.write(pack)
        print('Script md5: {}'.format(hashlib.md5(open(__file__, 'rb').read()).hexdigest()))

    except AttributeError as err:
        print(err)
        parser.print_help()
