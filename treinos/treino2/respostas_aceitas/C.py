d = {}

while True:
	try:
		killer, killed = input().split()
	except EOFError:
		break

	if killer in d:
		if d[killer] != -1:
			d[killer] += 1
	else:
		d[killer] = 1

	d[killed] = -1

final_list = []
for i in d:
	if d[i] != -1:
		final_list.append(i)
print("HALL OF MURDERERS")
for i in sorted(final_list):
	print(i, d[i])
