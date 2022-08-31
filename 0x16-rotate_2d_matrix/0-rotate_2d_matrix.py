#!/usr/bin/python3
"""0-rotate_2d_matrix.py """


def rotate_2d_matrix(matrix):
    """rotate 2d matrix"""
    x = 0
    while x < len(matrix[0]):
        for j in range(x, len(matrix[0])):
            aux = matrix[x][j]
            matrix[x][j] = matrix[j][x]
            matrix[j][x] = aux
        x += 1
    for j in range(len(matrix[0])):
        matrix[j].reverse()
