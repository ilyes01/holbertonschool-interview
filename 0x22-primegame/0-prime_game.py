#!/usr/bin/python3

def is_prime(n):
    """is prime"""
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def get_primes(n):
    """get prime"""

    primes = set()
    for i in range(2, n + 1):
        if is_prime(i):
            primes.add(i)
    return primes


def isWinner(x, nums):

    """is winner"""
    winners = []
    for n in nums:
        primes = get_primes(n)
        if len(primes) == 0:
            winners.append(None)
        elif len(primes) % 2 == 0:
            winners.append('Ben')
        else:
            winners.append('Maria')
    ben_wins = winners.count('Ben')
    maria_wins = winners.count('Maria')
    if ben_wins > maria_wins:
        return 'Ben'
    elif maria_wins > ben_wins:
        return 'Maria'
    else:
        return None
