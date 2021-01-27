#!/usr/bin/python3
"""Reads stdin line by line and computes metrics"""

import sys

if __name__ == "__main__":

    cnt = 1
    sCodes = [0, 0, 0, 0, 0, 0, 0, 0]
    size = 0
    sList = ["200", "301", "400", "401", "403", "404", "405", "500"]

    def printer(sCodes, status_L):
        """Printer method"""

        print("File size: {}".format(size))
        for mv in range(len(sCodes)):
            if sCodes[mv] > 0:
                print("{}: {}".format(sList[mv], sCodes[mv]))

    try:
        for line in sys.stdin:
            amount = line.split(" ")

            if len(amount) > 6:
                status = amount[-2]

                if status in sList:
                    mv = sList.index(status)
                    sCodes[mv] = sCodes[mv] + 1

                size = size + int(amount[-1][:])
                if cnt % 10 == 0:
                    printer(sCodes, sList)

            cnt = cnt + 1

    except KeyboardInterrupt:
        printer(sCodes, sList)
        raise

    printer(sCodes, sList)
