notas = (100, 50, 20, 10, 5, 2, 1)

total = int(input())

print(total)
for nota in notas:
	count = int(total/nota)
	print('{} nota(s) de R$ {},00'.format(count, nota))
	total %= nota