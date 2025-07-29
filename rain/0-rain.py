#!/usr/bin/python3
"""
Rain task
"""


def rain(walls):
    """
    Calculates the amount of rainwater trapped between
    walls after rainfall.

    This function processes a list of integers representing wall
    heights aligned on a grid.
    Each wall has a width of 1 unit. It returns the total amount
    of water that can be trapped
    between the walls after it rains.
    """
    # Return 0 if the input list is empty
    if not walls:
        return 0

    # Initialize pointers and variables to track water
    left = 0                # Start pointer at the left end
    right = len(walls) - 1  # Start pointer at the right end
    water = 0               # Total amount of trapped water

    # Track the maximum height encountered from the left and right
    left_max = walls[left]
    right_max = walls[right]

    # Traverse the list using two pointers
    while left < right:
        # If the wall on the left is shorter
        if walls[left] < walls[right]:
            left += 1  # Move the left pointer to the right
            if walls[left] < left_max:
                # If current wall is shorter than left_max, water is trapped
                water += left_max - walls[left]
            else:
                # Update left_max to the new taller wall
                left_max = walls[left]
        else:
            # If the wall on the right is shorter or equal
            right -= 1  # Move the right pointer to the left
            if walls[right] < right_max:
                # If current wall is shorter than right_max, water is trapped
                water += right_max - walls[right]
            else:
                # Update right_max to the new taller wall
                right_max = walls[right]

    # Return the total trapped water
    return water
