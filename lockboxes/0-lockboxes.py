#!/usr/bin/python3
"""
Exercice:
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    This function will check if all the boxes can be opened using
    a key found in another box.

    Args:
        boxes (list of lists): A list where each index represents a box,
        and the inner list contains keys to other boxes.

    Returns:
        bool: True if all boxes can be opened, otherwise False.

    Explanation:
        - We start with the first box (index 0) already opened.
        - We collect all keys found in the first box.
        - Using a loop, we check if the keys can unlock new boxes.
        - If a new box is opened, we add its keys to our collection.
        - This continues until no new keys are found.
        - If we have opened all boxes, return True; otherwise, return False.
    """
    if not isinstance(boxes, list):  # Ensure input is a list
        return False
    if len(boxes) == 0:  # Edge case: empty list
        return False

    n = len(boxes)
    opened = {0}  # Start with the first box opened
    keys = set(boxes[0])  # Collect keys from the first box

    while keys:  # While there are keys to process
        key = keys.pop()  # Take a key from the set
        # Check if key unlocks a new box
        if 0 <= key < n and key not in opened:
            opened.add(key)  # Mark box as opened
            # Add new keys from this box to our collection
            keys.update(boxes[key])

    return len(opened) == n  # Return True if all boxes are opened