#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""

import sys

data = {"Size": 0, "Codes": {"200": 0, "301": 0, "400": 0, "401": 0,
                             "403": 0, "404": 0, "405": 0, "500": 0}}


def printer():
    """Printer"""

    print("File size: {}".format(data['Size']))

    for sCode, mv in sorted(data['Codes'].items()):
        if mv != 0:
            print("{}: {}".format(sCode, mv))


if __name__ == "__main__":
    try:
        cnt = 1
        for line in sys.stdin:

            nLine = line.split(" ")

            try:
                size = int(nLine[-1])
                code = nLine[-2]

                if code in data['Codes']:
                    data['Codes'][code] += 1

                data['Size'] += size
            except:
                pass

            if cnt % 10 == 0:
                printer()

            cnt += 1

    except KeyboardInterrupt:
        printer()
        raise
    printer()
