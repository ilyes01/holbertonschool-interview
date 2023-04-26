#!/usr/bin/python3
"""functions"""


def generate_primes(n):
    """genetate primes"""
    primes = [True] * (n+1)
    primes[0] = primes[1] = False
    for i in range(2, int(n**0.5)+1):
        if primes[i]:
            for j in range(i*i, n+1, i):
                primes[j] = False
    return [i for i in range(2, n+1) if primes[i]]


def play_round(n):
    """play round"""
    primes = generate_primes(n)
    player = 'Maria'
    while True:
        if not primes:
            return 'Ben'
        p = primes[0]
        primes = [x for x in primes if x % p != 0]
        if player == 'Maria':
            player = 'Ben'
        else:
            player = 'Maria'
        if not primes:
            return player


def isWinner(x, nums):
    """ben is the winner"""
    wins = {'Maria': 0, 'Ben': 0}
    for n in nums:
        winner = play_round(n)
        wins[winner] += 1
    if wins['Maria'] > wins['Ben']:
        return 'Maria'
    elif wins['Ben'] > wins['Maria']:
        return 'Ben'
    else:
        return None
