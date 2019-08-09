""" Para cada coluna, devemos cortar o número de linhas "novas" em relação à coluna anterior.
    Portanto, começando com prev = altura, devemos encontrar a diferença entre a altura da
    coluna atual e à sua esquerda, e somar a diferença(quando positiva) ao total(count)"""

while True:
    a, c = map(int, input().split())
    if (a,c) == (0,0):
        break
    v = [int(x) for x in input().split()]

    count = 0
    prev = a
    for i in v:
        diff = prev - i
        if diff > 0:
            count += diff
        prev = i

    print(count)
