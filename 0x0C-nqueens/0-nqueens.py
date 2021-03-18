#!/usr/bin/python3

import sys
if len(sys.argv) is not 2:
    print('Usage: nqueens N')
    exit(1)
n = sys.argv[1]

try:
    n = int(n)

except:
    print('N must be a number')
    exit(1)

if n < 4:
    print('N must be at least 4')
    exit(1)

k = 1


def printert(table):
    DicQueens = []
    global k

    k += 1
    for i in range(n):
        for j in range(n):
            if table[i][j] == 1:
            	DicQueens.append([i, j])
    print(DicQueens)

def isSafe(table, col, row):
    for i in range(col):
        if (table[row][i]):
            return False

    i = row
    j = col
    while i >= 0 and j >= 0:
        if(table[i][j]):
            return False
        i -= 1
        j -= 1

    i = row
    j = col
    while j >= 0 and i < n:
        if(table[i][j]):
            return False

        i += 1
        j -= 1
    return True

def helper(table, col):
    if (col == n):
        printert(table)
        return True

    solv = False
    for i in range(n):
        if (isSafe(table, i, col)):
            table[i][col] = 1
            solv = helper(table, col + 1) or solv
            table[i][col] = 0
    return solv


def solver():
    table = [[0 for j in range(n)] for i in range(n)]
    if (helper(table, 0) is False):
        pass
        return
    return

solver()
