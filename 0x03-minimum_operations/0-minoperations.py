#!/usr/bin/python3
"""
Fewest number of operations needed
"""


def minOperations(n):
    """Fewest number of operations needed"""
    if n < 1:
        return 0

    cnt = 1
    save = 1
    pv = 1
    copy = 0
    paste = 0
    not1 = not3 = 0
    need = 0

    while cnt < n:
        if cnt != 1 and n % cnt == 0:
            if n % save == 0:
                pv = save
                not1 = 0
                cnt = save

            else:
                pv = cnt

            not3 = 0

            if not1 == 0:
                not1 = 1
                copy += 1

            paste += 1
            save += pv

        elif n % (cnt * 2) == 0:
    
            if not1 == 1:
                not1 = 0

            not3 = 0
            copy += 1
            pv = cnt
            paste += 1
            cnt = 2 * cnt
            save += (2 * pv) - save

        else:
            not1 = 0

            if not3 == 0:
                not3 = 1
                copy += 1
                pv = cnt

            cnt = cnt + pv
            paste += 1
            save += pv

        if save >= n:
            break

    need = copy + paste
    return need
