#!/usr/bin/python3
'''
Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
'''


def rain(walls):
    '''calculates how much water will be retained after it rains'''
    if len(walls) == 0:
        return 0

    result = 0

    # For every element in array
    for i in range(1, len(walls) - 1):

        # Find maximum element on left
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        # Find maximum element on right
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        # Update maximum water
        result = result + (min(left, right) - walls[i])

    return result
