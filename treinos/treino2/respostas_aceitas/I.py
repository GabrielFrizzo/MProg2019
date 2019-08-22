num = list(map(int,list(input())))

dig = [2]*10
saida=[]
i=0
problema = False
tam = len(num)
while(i<tam):
	if(dig[num[i]]>0):
		saida+=[num[i]]
		dig[num[i]]-=1
		i+=1
	else:
		saida+=[num[i]-1]
		problema=True
		break
if problema:
	while True:
		if saida[i]<0:
			saida = saida[:-1]
			i-=1
			dig[saida[i]]+=1
			saida[i]-=1
		elif dig[saida[i]]==0:
			saida[i]-=1
		else:
			dig[saida[i]]-=1
			break
	j=9
	while len(saida)<tam:
		if dig[j]>0:
			saida+=[j]
			dig[j]-=1
		else:
			j-=1
while(saida[0]==0 and len(saida)>1):
	saida=saida[1:]
saida = [str(c) for c in saida]
num =[str(c) for c in num]
print(''.join(saida))

