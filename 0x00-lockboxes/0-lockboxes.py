#!/usr/bin/python3


def canUnlockAll(boxes):
    '''checks if boxes contain keys to unlock all boxes
    '''
    if len(boxes) == 0:
        return True
    box_to_check = [0]
    unlocked = [False] * len(boxes)
    unlocked[0] = True

    while box_to_check:
        current_box = box_to_check.pop()
        for key in boxes[current_box]:
            if key > 0 and key < len(boxes)\
             and not unlocked[key]:
                unlocked[key] = True
                box_to_check.append(key)
    return all(unlocked)
