ls = [int(el) for el in input().split(" ")]             # Put input numbers into a list
res = [ls[i]/ls[i+1] for i in range(0, len(ls), 2)]     # Create a new list with division results
ind = res.index(max(res))                               # Get the index of the highest quotient
print(ls[2*ind], ls[2*ind+1])                           # Print the appropriate fraction
