#!/usr/bin/python3
'''
Find the minimum amount of operations using only Copy All and Paste to reach n
'''


def minOperations(n):
    '''find minimum amount'''
    if n <= 1:
        return 0
    else:
        for i in range(2, n + 1):
            if n % i == 0:
                return minOperations(int(n / i)) + i
