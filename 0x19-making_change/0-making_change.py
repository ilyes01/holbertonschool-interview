#!/usr/bin/python3
""" making_change """


def makeChange(coins, total):
    """fewest number of coin"""

    if total <= 0:
        return 0
    if not coins or min(coins) > total:
        return -1
    n_coins = 0
    coins.sort(reverse=True)
    x = 0
    while x < len(coins):
        if coins[x] <= total:
            n_coins += total // coins[x]
            total = total % coins[x]
        x += 1
    if total == 0:
        return n_coins
    else:
        return -1
