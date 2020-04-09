#!/usr/bin/python3
'''Method that determines if a given data set represents valid UTF-8'''


def validUTF8(data):
    '''Is this given data set valid UTF-8?'''
    num_bytes = 0
    mask_1 = 1 << 7     # 128 (8th bit from left -> most significant)
    mask_2 = 1 << 6     # 64 (7th bit from left -> next most significant)

    for i in data:          # Get the number of most significant bits
        mask = 1 << 7       # Starting byte of UTF-8 character
        if num_bytes == 0:
            while i & mask:
                num_bytes += 1
                mask >>= 1
            if num_bytes == 0:  # 1 byte characters
                continue
        else:
            if not (i & mask_1 and not (i & mask_2)):
                return False
        num_bytes -= 1
    return num_bytes == 0
    return count == 0
