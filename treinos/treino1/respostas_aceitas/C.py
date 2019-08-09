# C - URI 1266 - https://www.urionlinejudge.com.br/judge/en/problems/view/1266

while True:
    # Input parameters  
    size = int(input()) 
    if size == 0:
        break

    v = [int(i) for i in input().split()]
    count = 0
    i = -1
    
    # Find the first "1" in the array
    # Starts from it
    # This helps in specific situations with 0 as the first int
    for j in range(len(v)):
        if v[j] == 1:
            i = j
            break
    # If There is no "1" in the array
    # Just return the size divided by 2, rounded up
    if i == -1:
        print(int((size+1)/2))
        continue

    #index keeps the start index
    index = i
    while True: 
        # While is checking every pos in array
        # Looking for a pair of "0"
        if v[i%size] == 0 and v[(i+1)%size] == 0:
            count += 1
            i += 1
            # If i is equals to the end pos, break
            if i%size == (abc-1)%size:
                break
        # Go for the next pos on the array
        i += 1
        if i%size == (abc-1)%size:
            break

    print(count)




