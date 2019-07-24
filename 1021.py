notas = (100, 50, 20, 10, 5, 2)
moedas = (50, 25, 10, 5, 1)

reais, centavos = map(int, input().split('.'))

print('NOTAS:')
for nota in notas:
	count = int(reais/nota)
	print('{} nota(s) de R$ {}.00'.format(count, nota))
	reais %= nota

print('MOEDAS:')
print('{} moeda(s) de R$ 1.00'.format(reais%2))
for moeda in moedas:
	count = int(centavos/moeda)
	print('{} moeda(s) de R$ 0.{:02}'.format(count, moeda))
	centavos %= moeda