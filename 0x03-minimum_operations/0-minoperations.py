#!/usr/bin/python3
"""
minoperation
"""
def minOperations(n):
    if type(n) is not int or n < 2:
        return 0
    op = 0
    for i in range(2, int(n ** (1 / 2))):
        while n % i == 0:
            op += i
            n = n/i
    if n > 1:
        op += n
    return int(op)
