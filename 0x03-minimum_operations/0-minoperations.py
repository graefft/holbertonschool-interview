#!/usr/bin/python3
'''
Find the minimum amount of operations using only Copy All and Paste to reach n
'''


def minOperations(n):
    '''find minimum amount'''
    steps = n
    factor = 0
    if n <= 0:
        return 0
    if ((n % 2 != 0) and (n % 3 != 0)):
        return n
    else:
        half = n / 2
        for i in range(2, int(half) + 1):
            if (n % i == 0):
                factor = int(n / i)
                if (factor + i) < steps:
                    steps = factor + i
    return steps
