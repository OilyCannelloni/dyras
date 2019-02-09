lengths = [len(el) for el in input().split(" ")]    # Get word lengths
for i in range(1, 13):  # For every length from 1 to 12 inclusive
    if i not in lengths:    # If it hasn't been used
        print(i, end=" ")   # Print it with a space instead of '\n'
