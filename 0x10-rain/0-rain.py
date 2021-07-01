#!/usr/bin/python3
"""Given a list of non-negative integers representing walls of width 1
calculate how much water will be retained after it rains"""


def rain(walls):
    """Rain"""
    if type(walls) is not list:
        return 0

    if len(walls) is 0:
        return 0

    water = 0

    for index, mv in enumerate(walls):
        if index != 0 and index != (len(walls) - 1):
            l = max(walls[0:index])
            r = max(walls[index + 1:len(walls)])

            if mv < r and mv < l:
                water += min([l, r]) - mv
    return water
