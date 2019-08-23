from math import ceil

a,b=(1,1)

while a > 0 and b > 0:
	a,b = [int(x) for x in input().split()]
	if a == 0 and b == 0:
		break
	_max = max(a,b)
	_min = min(a,b)
	if _min == 1:
		print(_max)
	elif _min == 2:
		print(int(_max/4)*4 + min(_max%4,2)*2)
	else:
		print(ceil(a*b/2))
