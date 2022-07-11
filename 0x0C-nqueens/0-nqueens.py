#!/usr/bin/python3
import sys
if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)
if sys.argv[1].isdigit() is False:
    print('N must be a number')
    exit(1)
N = int(sys.argv[1])
if (N < 4):
    print('N must be at least 4')
    exit(1)
a = 0
frequence_a    a += 1
    n = a
    for b in range(N):
        Lists.append([b, a])
        if (a + frequence_a > N-1):
            a += frequence_a - 1 - N
        else:
            a += frequence_a
    print(Lists)
    frequence_a += 1
    a = n
exit(0)
