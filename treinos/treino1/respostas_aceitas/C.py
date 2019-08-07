while True:
    size = int(input())
    if size == 0:
        break

    v = [int(i) for i in input().split()]
    count = 0
    i = -1
    for j in range(len(v)):
        if v[j] == 1:
            i = j
            break
    if i == -1:
        print(int((size+1)/2))
        continue

    abc = i
    while True: 
        if v[i%size] == 0 and v[(i+1)%size] == 0:
            count += 1
            i += 1
            if i%size == (abc-1)%size:
                break
        i += 1
        if i%size == (abc-1)%size:
            break

    print(count)




