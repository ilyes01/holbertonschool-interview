#!/usr/bin/python3
"""
Prototype: def minOperations(n)
Returns an integer
If n is impossible to achieve, return 0
"""


def factorization(n):
    x = 2
    y = 0
    while x <= n:
        if n % x == 0:
            n = n // x
            y += x
            x -= 1
        x += 1
    return y


def minOperations(n):
    if not isinstance(n, int) or n < 2:
        return 0
    return factorization(n)
