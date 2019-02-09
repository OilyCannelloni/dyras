for _ in range(int(input())):   # Repeat n times
    counter = 0                 # Declare counter
    r = input().split(" ")      # Get input integers
    for i in range(int(r[0])+1, int(r[1])):     # For all numbers between a and b
        dgs = str(i)                            # Make the number a string containing its digits
        if 2*len(list(d for d in dgs if d in "02468")) == len(dgs):
            # If the [amount of even digits]*2 is equal to the number of digits
            counter += 1    # Increment counter
    print(counter)
