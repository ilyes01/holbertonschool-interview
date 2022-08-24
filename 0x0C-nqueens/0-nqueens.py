#!/usr/bin/python3
import sys

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    b = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)
if b < 4:
    print("N must be at least 4")
    exit(1)


def chest(b, place1, sold):
    for x in range(b):
        c = 0
        for quen in sold:
            if x == quen[1]:
                c = 1
                break
            if place1 - x == quen[0] - quen[1]:
                c = 1
                break
            if x - quen[1] == quen[0] - place1:
                c = 1
                break
        if c == 0:
            sold.append([place1, x])
            if place1 != b - 1:
                chest(b, place1 + 1, sold)
            else:
                print(sold)
            del sold[-1]


chest(b, 0, [])
