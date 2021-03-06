#!/usr/bin/python3
"""All rights to leetcode.com"""


def validUTF8(data):

    n_bytes = 0
    mask1 = 1 << 7
    mask2 = 1 << 6

    for cntnum in data:
        mask = 1 << 7
        if n_bytes == 0:
            while mask & cntnum:
                n_bytes += 1
                mask = mask >> 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (cntnum & mask1 and not (cntnum & mask2)):
                return False
        n_bytes -= 1
    return n_bytes == 0
