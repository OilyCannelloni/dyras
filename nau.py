ls = list([int(el) for el in input().split(" ")])
res = []
for i in [0, 2, 4]:
    res.append(ls[i]/ls[i+1])
ind = res.index(max(res))
print(ls[2*ind], ls[2*ind+1], end=" ")
