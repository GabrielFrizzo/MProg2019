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
