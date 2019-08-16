while True:
	try:
		texto = input()
	except:
		break

	direita = True
	saida='' 
	comeco=0
	for i in range(0, len(texto)):
		if texto[i]=='[' or texto[i]==']':
			if direita:
				saida+=texto[comeco:i]
			else:
				saida=texto[comeco:i]+saida
			if texto[i]=='[':
				direita = False
			else:
				direita = True
			comeco = i+1
	
	if direita:
		saida+=texto[comeco:len(texto)]
	else:
		saida=texto[comeco:len(texto)]

	print(saida)

