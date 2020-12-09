#!/usr/bin/python3
"""
Module.
"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened"""

    key = 0
    holder = [0]
    if len(boxes) == 0:
        return True

    for key in holder:
        for key in boxes[key]:

            if key in holder:
                continue

            else:
                if key <= len(boxes) - 1:
                    holder.append(key)

                else:
                    continue

    if len(boxes) != len(holder):
        return False
    else:
        return True
