#!/usr/bin/python3
'''
Given a pile of coins of different values, determine the fewest number of coins
needed to meet a given amount total.
'''


def makeChange(coins, total):
    '''return fewest number of coins needed'''
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    i = 0
    count = 0
    for i in range(len(coins)):
        while ((total - coins[i]) >= 0):
            total = total - coins[i]
            count += 1
    if (total == 0):
        return count
    else:
        return -1
