#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics"""

import sys

if __name__ == "__main__":

    increase = 1
    status_code = [0, 0, 0, 0, 0, 0, 0, 0]
    size = 0
    status_L = ["200", "301", "400", "401", "403", "404", "405", "500"]

    def signal_print(status_code, status_L):
        """ Method to handle ctrl-c"""
        print("File size: {}".format(size))
        for i in range(len(status_code)):
            if status_code[i] > 0:
                print("{}: {}".format(status_L[i], status_code[i]))

    try:
        for line in sys.stdin:
            each_argvs = line.split(" ")
            if len(each_argvs) > 6:
                status = each_argvs[-2]
                if status in status_L:
                    i = status_L.index(status)
                    status_code[i] = status_code[i] + 1
                size = size + int(each_argvs[-1][:])
                if increase % 10 == 0:
                    signal_print(status_code, status_L)
            increase = increase + 1
    except KeyboardInterrupt:
        signal_print(status_code, status_L)
        raise
    signal_print(status_code, status_L)
    