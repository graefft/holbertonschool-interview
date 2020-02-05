#!/usr/bin/python3


def canUnlockAll(boxes):
    '''checks if boxes contain keys to unlock all boxes
    '''
    if len(boxes) == 0:
        return True
    lock_to_check = [0]
    unlocked = [False] * len(boxes)
    unlocked[0] = True

    while lock_to_check:
        current_lock = lock_to_check.pop()
        for lock in boxes[current_lock]:
            if lock > 0 and lock < len(boxes)\
             and not unlocked[lock]:
                unlocked[lock] = True
                lock_to_check.append(lock)
    return all(unlocked)
