#!/usr/bin/python3
'''NQUEENS'''

import sys
from copy import deepcopy


def setup():
    '''prepares board and checks for errors'''
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)
    try:
        n = int(sys.argv[1])
    except Exception:
        print('N must be a number')
        exit(1)
    if n < 4:
        print('N must be at least 4')
        exit(1)
    board = [0 for i in range(n)]
    return board


def nqueens(board, col):
    '''recursively places queen and calls check isSafe()'''
    size = len(board)
    if col == size:
        print(str([[i, board[i]] for i in range(size)]))
        return
    for row in range(size):
        if isSafe(board, row, col):
            board[col] = row
            nqueens(board, col + 1)


def isSafe(board, row, col):
    '''checks if Queen can not attack or be attacked by another Queen'''
    for i in range(col):
        if board[i] == row:
            return False
        if abs(board[i] - row) == abs(i - col):
            return False
    return True

if __name__ == '__main__':
    board = setup()
    nqueens(board, 0)
