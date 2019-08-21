# DFS checando por ciclo

from collections import defaultdict

I, N, O = [int(x) for x in input().split()]
d = {}
visited = set()
ancestors = set()

def visita(n):
    if n in ancestors: return False
    if n in visited: return True
    visited.add(n)
    if n <= I: return True
    ancestors.add(n)

    flag = False
    for i in d[n]:
        if visita(i):
            flag = True
        else:
            return False
    ancestors.remove(n)
    return flag

for i in range(I+1,I+N+1):
    inp = input().split()
    d[i] = [int(x) for x in inp[1:]]

for i in [int(x) for x in input().split()]:
    if not visita(i):
        print("u.u")
        exit()

if len(visited) < I+N:
    print("u.u")
else:
    print("o.o")
