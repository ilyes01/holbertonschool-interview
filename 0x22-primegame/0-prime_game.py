#!/usr/bin/python3
"""This module contains the function isWinner"""


def isWinner(x, nums):
    """Determines the winner"""
    # end of function

    def is_prime(n):
        if n < 2:
            return False
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True

    wins = {"Maria": 0, "Ben": 0}

    for i in range(x):
        n = nums[i]
        primes = set()
        for j in range(1, n + 1):
            if is_prime(j):
                primes.add(j)
        turn = "Maria"
        while len(primes) > 0:
            if turn == "Maria":
                prime = max(primes)
                primes -= set(range(prime, n + 1, prime))
                if prime == 1:
                    turn = "Ben"
                else:
                    turn = "Ben"
            else:
                prime = min(primes)
                primes -= set(range(prime, n + 1, prime))
                if prime == 1:
                    turn = "Maria"
                else:
                    turn = "Maria"
        if turn == "Maria":
            wins["Ben"] += 1
        else:
            wins["Maria"] += 1

    if wins["Maria"] > wins["Ben"]:
        return "Maria"
    elif wins["Ben"] > wins["Maria"]:
        return "Ben"
    else:
        return None
