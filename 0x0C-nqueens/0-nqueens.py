#!/usr/bin/python3
import sys


if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)

cnt = sys.argv[1]

try:
    cnt = int(cnt)

except:
    print('N must be a number')
    exit(1)

if cnt < 4:
    print('N must be at least 4')
    exit(1)


def printer(table):
    aux = 1
    DicQueens = []
    aux += 1
    for i in range(cnt):
        for j in range(cnt):
            if table[i][j] == 1:
                DicQueens.append([i, j])
    print(DicQueens)


def safe(table, row, colm):
    for i in range(colm):
        if (table[row][i]):
            return False
    x = colm
    y = row

    while y >= 0 and x >= 0:
        if(table[y][x]):
            return False
        x -= 1
        y -= 1

    y = row
    x = colm

    while y < cnt and x >= 0:
        if(table[y][x]):
            return False
        x -= 1
        y += 1
    return True


def helper(table, colm):
    if (colm == cnt):
        printer(table)
        return True

    sol = False
    for mv in range(cnt):
        if (safe(table, mv, colm)):
            table[mv][colm] = 1
            sol = helper(table, colm + 1)
            table[mv][colm] = 0
    return sol


def solver():
    table = [[0 for j in range(cnt)] for mv in range(cnt)]
    if (helper(table, 0) is False):
        pass
        return
    return
solver()
