from sys import stdin

for inp in stdin:
	a, b = map(int, inp.split(' '))
	print(a ^ b)