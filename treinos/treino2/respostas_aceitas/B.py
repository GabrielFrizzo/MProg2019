# A parte dificil deste problema é compreender o enunciado.
# Basicamente, aplicamos a função f à matriz original até que
# ela se torne uma matriz de zeros, e contamos quantas iterações
# este processo leva.

TC = int(input())

def f(m):
    res = [[0]*3 for _ in range(3)]
    for i in range(3):
        for j in range(3):
            for x in (-1,1):
                if i+x>=0 and i+x<3:
                    res[i][j] = (res[i][j]+m[i+x][j])%2
                if j+x>=0 and j+x<3:
                    res[i][j] = (res[i][j]+m[i][j+x])%2
    return res

def iszero(m):
    for i in range(3):
        for j in range(3):
            if m[i][j] != 0:
                return False
    return True

for _ in range(TC):
    input()
    m = []
    for _ in range(3):
        m.append([int(x) for x in list(input())])
    count = -1
    while not iszero(m):
        count += 1
        m = f(m)
    print(count)
