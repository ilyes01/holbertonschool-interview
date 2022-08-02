#!/usr/bin/python3
"""
calculate how many square units of water will
be retained after it rains
"""


def rain(walls):
    """
    rain function
    """
    if walls is None or walls == []:
        return 0
    if len(walls) == 1:
        return 0

    a = len(walls)
    left_side = [0] * a

    right_side = [0] * a
    wat = 0

    left_side[0] = walls[0]
    for x in range(1, a):
        left_side[x] = max(left_side[x - 1], walls[x])

    right_side[a - 1] = walls[a - 1]
    for x in range(a - 2, -1, -1):
        right_side[x] = max(right_side[x + 1], walls[x])

    for x in range(0, a):
        wat += min(left_side[x], right_side[x]) - walls[x]

    return wat
