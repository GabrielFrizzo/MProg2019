med = {}

while True:
	try:
		input()
		for m in range(3):
			c = input()
			if c not in med:
				med[c] = [0,0,0]
			med[c][m] += 1
	except EOFError:
		break
def bigger(x):
	return med[x]

print("Quadro de Medalhas")
for c in sorted(sorted(med.keys()), key=bigger, reverse=True):
	print(c, *med[c])
