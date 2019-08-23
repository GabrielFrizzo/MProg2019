# Tirando os casos em que a menor dimensao é 1 ou 2, temos a*b/2 arredondado para cima como a resposta

from math import ceil

a,b=(1,1)

def imprime_frase(n):
    print('{} knights may be placed on a {} row {} column board.'.format(n, a, b))

while a > 0 and b > 0:
	a,b = [int(x) for x in input().split()]
	if a == 0 and b == 0:
		break
	_max = max(a,b)
	_min = min(a,b)
	if _min == 1:
		imprime_frase(_max)
	elif _min == 2:
		imprime_frase(int(_max/4)*4 + min(_max%4,2)*2)
	else:
		imprime_frase(ceil(a*b/2))
