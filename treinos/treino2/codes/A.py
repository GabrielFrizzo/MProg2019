I, N, o = [int(x) for x in input().split()]
d = {}
res = [-1]*(I+N)

def visita(n, s):
	if res[n] == s: return False
	if n < I: return True
	res[n] = s
	for i in d[n]:
		if not visita(i,s):
			return False

for i in range(I+1,I+N+2):
	d[i] = [int(x) for x in input().split()]

for i in [int(x) for x in input().split()]:
	if not visita(i,i):
		print("u.u")
		exit(0)

if -1 in res:
	print("u.u")
else:
	print("o.o")
