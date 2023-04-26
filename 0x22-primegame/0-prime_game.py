#!/usr/bin/python3
"""fucntion"""


def is_prime(n):
    """Returns True if n is prime, False otherwise."""
    if n <= 1:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def isWinner(x, nums):
    """Determines the winner of each game."""
    maria_wins = 0
    ben_wins = 0
    for n in nums:
        prime_nums = [i for i in range(2, n+1) if is_prime(i)]
        maria_moves = 0
        ben_moves = 0
        while prime_nums:
            if maria_moves == ben_moves:

                for prime in prime_nums:
                    multiples = [i for i in range(prime, n+1, prime)]
                    if set(multiples).issubset(set(prime_nums)):
                        prime_nums = list(set(prime_nums) - set(multiples))
                        maria_moves += 1
                        break
                else:
                    ben_wins += 1
                    break
            else:
                for prime in prime_nums:
                    multiples = [i for i in range(prime, n+1, prime)]
                    if set(multiples).issubset(set(prime_nums)):
                        prime_nums = list(set(prime_nums) - set(multiples))
                        ben_moves += 1
                        break
                else:

                    maria_wins += 1
                    break
        else:
            if maria_moves == ben_moves:
                ben_wins += 1
            elif maria_moves > ben_moves:
                maria_wins += 1
            else:
                ben_wins += 1
    if maria_wins == ben_wins:
        return None
    elif maria_wins > ben_wins:
        return "Maria"
    else:
        return "Ben"
