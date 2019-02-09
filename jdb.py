lengths = list(len(el) for el in input().split(" "))
for i in range(1, 13):
    if i not in lengths:
        print(i, end=" ")
