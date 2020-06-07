#!/usr/bin/python3
'''
Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
'''


def rain(walls):
    '''calculates how much water will be retained after it rains'''
    if len(walls) == 0:
        return 0
    u = 0
    w = 0
    lo = 0
    hi = 0
    for i in range(len(walls)):
        w = 0
        while ((walls[lo] < 1) and lo < len(walls)):
            lo = lo + 1
        if hi < len(walls) - 1:
            hi = lo + 1
        while ((walls[hi] < 1) and hi < len(walls)):
            hi = hi + 1
            w = w + 1
        if walls[hi] > walls[lo]:
            u = u + (w * walls[lo])
        else:
            u = u + (w * walls[hi])
        print('u = {} | w = {} | lo = {} | hi = {}'.format(u, w, lo, hi))
        lo = lo + 1
        if hi == len(walls) - 1:
            break
    return u
