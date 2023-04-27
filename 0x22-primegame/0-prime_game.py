#!/usr/bin/python3
"""python function"""


def is_prime(n):
    """Check if a number is prime"""
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def get_primes(n):
    """Get the set of prime numbers up to n"""
    primes = set()
    for i in range(2, n + 1):
        if is_prime(i):
            primes.add(i)
    return primes


def isWinner(x, nums):
    """Determine the winner of the game"""
    ben_wins = 0
    maria_wins = 0
    for n in nums:
        primes = get_primes(n)
        if len(primes) == 0:
            continue
        elif len(primes) % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1
    if ben_wins > maria_wins:
        return "Winner: Ben"
    elif maria_wins > ben_wins:
        return "Winner: Maria"
    else:
        return None
