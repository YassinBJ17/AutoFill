synergy_tag = '%full_name:  sknNEXT#1/ascii/createSHA256.py/1 %'

(_, tag, _) = synergy_tag.split()
(instance, ftype, fname, version) = tag.split('/')
__version__ = version + ':' + instance

import argparse
import hashlib
import struct

hash_format = '>I32s'

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Concatenate all input files and append a CRC32',
                                    fromfile_prefix_chars='@')

    parser.add_argument('-o', '--output', type=argparse.FileType('wb'), help='Output file')
    parser.add_argument('-i', '--input', type=argparse.FileType('rb'), help='Input file to append hash to')
    parser.add_argument('-n', '--naked', type=argparse.FileType('wb'), help='Output file to store hash in')
    parser.add_argument('inputs', type=argparse.FileType('rb'), nargs='+', help='Input files to compute hash from')
    parser.add_argument('--version', action='version', version=fname + '~' + __version__,
                        help='Show program version info and exit.')

    try:
        args = parser.parse_args()
        data = bytes()

        for f in args.inputs:
            buff = f.read()
            sha = hashlib.sha256(buff)
            print('{} *{}'.format(sha.hexdigest(), f.name))
            data += struct.pack(hash_format, len(buff), sha.digest())

        if args.naked != None:
            args.naked.write(data)

        if args.input != None:
            data = args.input.read() + data

        if args.output != None:
            args.output.write(data)

        print('Script md5: {}'.format(hashlib.md5(open(__file__, 'rb').read()).hexdigest()))

    except AttributeError as err:
        print(err)
        parser.print_help()
