#!/usr/bin/python3
""" function """

import sys

"""user should called the program with the right arguments"""
if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
""" n must be a number"""
try:
    b = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)
"""n should be bigger than four"""
if b < 4:
    print("N must be at least 4")
    exit(1)


def chess(b, pla1, sold):
    """nqueens function"""
    for x in range(b):
        col = 0
        for quen in sold:
            if x == quen[1]:
                col = 1
                break
            if pla1 - x == quen[0] - quen[1]:
                col = 1
                break
            if x - quen[1] == quen[0] - pla1:
                col = 1
                break
        if col == 0:
            sold.append([pla1, x])
            if pla1 != b - 1:
                chest(b, pla1 + 1, sold)
            else:
                print(sold)
            del sold[-1]


chess(b, 0, [])
