#!/usr/bin/python3
'''Script that reads `stdin` line by line and computes metrics'''


import sys

if __name__ == '__main__':

    def print_stats():
        '''Prints total File Size and number of lines of each valid status code'''
        print("File size: {}".format(total_size))
        for code in sorted(codes.keys()):
            if codes[code]:
                print("{}: {}".format(code, codes[code]))

    codes = {"200": 0, "301": 0, "400": 0, "401": 0,
             "403": 0, "404": 0, "405": 0, "500": 0}
    count = 0
    total_size = 0

    try:
        for line in sys.stdin:
            count += 1
            data = line.split()
            try:
                total_size += int(data[-1]) # Add last column (file_size)
            except:
                pass
            try:
                status_code = data[-2]      # Check for status code 2nd column to right
                if status_code in codes:
                    codes[status_code] += 1
            except:
                pass
            if count % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        print_stats()
