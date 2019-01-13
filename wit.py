n = int(input())
p = {'A': 999999, 'B': 999999, 'C': 999999, 'AB': 999999, 'BC': 999999, 'AC': 999999, 'ABC': 999999}
for i in range(n):
    inp = input().split(" ")
    inp[1] = ''.join(sorted(list(inp[1])))
    inp[1] += 'AC' if inp[1] == 'ABC' else ''
    for el in p.keys():
        p[el] = (int(inp[0]) if el in inp[1] and int(inp[0]) < p[el] else p[el]) 
        
for el in ['A', 'B', 'C']:
    p[el] = min({k: v for k, v in p.items() if el in k}.values())
    
if 999999 in (p[el] for el in ['A', 'B', 'C']):
    print(-1)
else:
    print(min([p['A'] + p['B'] + p['C'], p['A'] + p['BC'], p['B'] + p['AC'], p['C'] + p['AB'], p['ABC']]))
