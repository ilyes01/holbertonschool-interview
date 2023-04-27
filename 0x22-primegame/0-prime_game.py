#!/usr/bin/python3
"""py function"""


def isWinner(x, nums):
    """
    Determines the winner of a prime game for each round.

    """
    def get_primes(n):
        """Returns a list of prime numbers"""
        sieve = [True] * (n + 1)
        sieve[0] = sieve[1] = False
        for i in range(2, int(n ** 0.5) + 1):
            if sieve[i]:
                sieve[i*i:n+1:i] = [False] * ((n - i*i) // i + 1)
        return [i for i in range(n + 1) if sieve[i]]

    def play_game(primes, n):
        """Determines the winner of a prime game    """
        remaining = set(range(2, n + 1))
        turn = 1
        while remaining:
            for prime in primes:
                if prime in remaining:
                    remaining -= set(range(prime, n + 1, prime))
                    break
            else:
                break
            turn = 3 - turn
        return turn
    wins = [0, 0]
    for i in range(x):
        primes = get_primes(nums[i])
        winner = play_game(primes, nums[i])
        if winner is not None:
            wins[winner - 1] += 1
    if wins[0] > wins[1]:
        return "Maria"
    elif wins[1] > wins[0]:
        return "Ben"
    else:
        return None
