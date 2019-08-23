input()

arr = [int(x) for x in input().split()]

prev = -1
count = 0
for i in arr:
	if i > prev:
		count += 1

	prev = i

print(count)
