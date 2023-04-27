#!/usr/bin/python3
""" primegame """


def isPrime(x):
    """ checks if a number is prime """
    if x < 2:
        return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True


def isWinner(x, nums):
    """ prime game """
    if x < 1 or not nums or nums == []:
        return None
    r = min(x, len(nums))
    maria_wins = 0
    ben_wins = 0
    for r_i in range(r):
        n = list(range(2, nums[r_i] + 1))
        is_maria = True
        while n:
            p = n.pop(0)
            is_prime = isPrime(p)
            has_primes = False
            for i in range(p, nums[r_i] + 1, p):
                if i in n:
                    n.remove(i)
                    has_primes = True
            if not has_primes:
                break
            is_maria = not is_maria if is_prime else is_maria
        if is_maria:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return 'Maria'
    elif ben_wins > maria_wins:
        return 'Ben'
    return None
