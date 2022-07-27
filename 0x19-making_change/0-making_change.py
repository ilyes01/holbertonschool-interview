#!/usr/bin/python3
""" making_change """


def makeChange(coins, total):
    """fewest number of coin"""

    c = 0
    coins = sorted(coins, reverse=True)
    for ele in coins:
        if total // ele != 0:
            c += total // ele
            total = total % ele
    if total == 0:
        return c
    else:
        return -1
