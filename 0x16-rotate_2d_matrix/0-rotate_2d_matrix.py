#!/usr/bin/python3
"""0-rotate_2d_matrix.py """


def rotate_2d_matrix(matrix):
    """rotate 2d matrix"""
    x = 0
    while x < len(matrix[0]):
        for i in range(x, len(matrix[0])):
            aux = matrix[x][i]
            matrix[x][i] = matrix[i][x]
            matrix[i][x] = aux
        x += 1
    for i in range(len(matrix[0])):
        matrix[i].reverse()
