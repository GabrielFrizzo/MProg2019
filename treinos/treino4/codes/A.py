T = int(input())

for i in range(T):
    a, b = [int(x) for x in input().split()]

    if a < b or (a - b)%2 == 1:
        print('impossible')
    else:
        x = int((a+b)/2)
        y = a-x
        print(max(x, y), min(x,y))
