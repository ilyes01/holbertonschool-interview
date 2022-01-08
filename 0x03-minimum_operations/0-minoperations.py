#!/usr/bin/python3
"""
mimoperation
"""


def minOperations(n):
if n <= 1:
return 0
if n == 2:
return 2
else:
for i in range(n - 1, 0, -1):
if n % i == 0:
op = n // i
return op + minOperations(i)
