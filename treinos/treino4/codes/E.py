N = int(input())
G = []

for i in range(N):
    G.append([(not bool(int(x))) for x in input().split()])

not_visited = set(range(N))
lado1 = set([])
lado2 = set([])

def visit(curr, lado):
    if lado:
        lado2.add(curr)
    else:
        lado1.add(curr)
    for i in range(N):
        if G[curr][i]:
            if (lado and i in lado2) or (not lado and i in lado1):
                return False
            elif i in not_visited:
                not_visited.remove(i)
                if not visit(i, not lado):
                    return False
    return True

flag = True
while not_visited != set([]):
    if not visit(not_visited.pop(), False):
        print('Fail!')
        flag = False

if flag:
    print("Bazinga!")
