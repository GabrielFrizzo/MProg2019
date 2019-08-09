# para cada posição em um tabuleiro de xadrez, deve-se saber quais dessas não tem peças ou não então sendo ameaçadas por outras peças

#include<stdio.h>
#include<string.h>

int i, linha, coluna;
char fen[100];
char tabuleiro[8][8];

void preencherCasas(int l, int c)
{
	int i,j;	
	if(tabuleiro[l][c]=='p')
	{
		if(tabuleiro[l+1][c+1]==' ' && l+1<8 && c+1<8)
			tabuleiro[l+1][c+1]='x';
		if(tabuleiro[l+1][c-1]==' ' && l+1<8 && c-1>=0)
			tabuleiro[l+1][c-1]='x';
	}
	else if(tabuleiro[l][c]=='P'){
		if(tabuleiro[l-1][c+1]==' ' && l-1>=0 && c+1<8)
			tabuleiro[l-1][c+1]='x';
		if(tabuleiro[l-1][c-1]==' ' && l-1>=0 && c-1>=0)
			tabuleiro[l-1][c-1]='x';
	}
	else if(tabuleiro[l][c]=='r'||tabuleiro[l][c]=='R'){
		for (i=1;i+c<8 && (tabuleiro[l][c+i]=='x'|| tabuleiro[l][c+i]==' ');i++)
			tabuleiro[l][c+i]='x';			
		for (i=1;c-i>=0 && (tabuleiro[l][c-i]=='x'|| tabuleiro[l][c-i]==' ');i++)
			tabuleiro[l][c-i]='x';			
		for (i=1;l+i<8 && (tabuleiro[l+i][c]=='x'|| tabuleiro[i+l][c]==' ');i++)
			tabuleiro[l+i][c]='x';			
		for (i=1;l-i>=0 && (tabuleiro[l-i][c]=='x'|| tabuleiro[l-i][c]==' ');i++)
			tabuleiro[l-i][c]='x';			
	}	
	else if(tabuleiro[l][c]=='b'||tabuleiro[l][c]=='B'){
		for (i=1;c+i< 8 && l+i<8 && (tabuleiro[l+i][c+i]=='x'|| tabuleiro[l+i][c+i]==' ');i++)
			tabuleiro[l+i][c+i]='x';			
		for (i=1;c-i>=0 && l+i<8 && (tabuleiro[l+i][c-i]=='x'|| tabuleiro[l+i][c-i]==' ');i++)
			tabuleiro[l+i][c-i]='x';			
		for (i=1;c+i<8 && l-i>=0 && (tabuleiro[l-i][c+i]=='x'|| tabuleiro[l-i][c+i]==' ');i++)
			tabuleiro[l-i][c+i]='x';			
		for (i=1;c-i>=0 && l-i>=0 && (tabuleiro[l-i][c-i]=='x'|| tabuleiro[l-i][c-i]==' ');i++)
			tabuleiro[l-i][c-i]='x';			
	}
	else if(tabuleiro[l][c]=='q'||tabuleiro[l][c]=='Q'){
		for (i=1;i+c<8 && (tabuleiro[l][c+i]=='x'|| tabuleiro[l][c+i]==' ');i++)
			tabuleiro[l][c+i]='x';			
		for (i=1;c-i>=0 && (tabuleiro[l][c-i]=='x'|| tabuleiro[l][c-i]==' ');i++)
			tabuleiro[l][c-i]='x';			
		for (i=1;l+i<8 && (tabuleiro[l+i][c]=='x'|| tabuleiro[i+l][c]==' ');i++)
			tabuleiro[l+i][c]='x';			
		for (i=1;l-i>=0 && (tabuleiro[l-i][c]=='x'|| tabuleiro[l-i][c]==' ');i++)
			tabuleiro[l-i][c]='x';			
		for (i=1;c+i< 8 && l+i<8 && (tabuleiro[l+i][c+i]=='x'|| tabuleiro[l+i][c+i]==' ');i++)
			tabuleiro[l+i][c+i]='x';			
		for (i=1;c-i>=0 && l+i<8 && (tabuleiro[l+i][c-i]=='x'|| tabuleiro[l+i][c-i]==' ');i++)
			tabuleiro[l+i][c-i]='x';			
		for (i=1;c+i<8 && l-i>=0 && (tabuleiro[l-i][c+i]=='x'|| tabuleiro[l-i][c+i]==' ');i++)
			tabuleiro[l-i][c+i]='x';			
		for (i=1;c-i>=0 && l-i>=0 && (tabuleiro[l-i][c-i]=='x'|| tabuleiro[l-i][c-i]==' ');i++)
			tabuleiro[l-i][c-i]='x';			
	}
	else if(tabuleiro[l][c]=='k'||tabuleiro[l][c]=='K'){
		if(l+1 < 8 && tabuleiro[l+1][c]==' ')
			tabuleiro[l+1][c]='x';
		if(l-1 >= 0 &&tabuleiro[l-1][c]==' ')
			tabuleiro[l-1][c]='x';		
		if(c+1 < 8 &&tabuleiro[l][c+1]==' ')
			tabuleiro[l][c+1]='x';
		if(c-1 >= 0 &&tabuleiro[l][c-1]==' ')
			tabuleiro[l][c-1]='x';		
		if(l+1 < 8 && c+1 < 8 &&tabuleiro[l+1][c+1]==' ')
			tabuleiro[l+1][c+1]='x';
		if(l-1 >= 0 && c-1 >= 0 &&tabuleiro[l-1][c-1]==' ')
			tabuleiro[l-1][c-1]='x';		
		if(l-1 >= 0 &&c+1 < 8 &&tabuleiro[l-1][c+1]==' ')
			tabuleiro[l-1][c+1]='x';
		if(l+1 < 8 && c-1 >= 0 &&tabuleiro[l+1][c-1]==' ')
			tabuleiro[l+1][c-1]='x';		
	}	
	else if(tabuleiro[l][c]=='n'||tabuleiro[l][c]=='N'){
		if(l+2 < 8 && c+1 < 8 && tabuleiro[l+2][c+1]==' ')
			tabuleiro[l+2][c+1]='x';
		if(l+2 < 8 && c-1 >= 0 && tabuleiro[l+2][c-1]==' ')
			tabuleiro[l+2][c-1]='x';		
		if(l-2 >= 0 && c+1 < 8 &&tabuleiro[l-2][c+1]==' ')
			tabuleiro[l-2][c+1]='x';
		if(l-2 >= 0 && c-1 >= 0 &&tabuleiro[l-2][c-1]==' ')
			tabuleiro[l-2][c-1]='x';		
		if(l+1 < 8 && c+2 < 8 &&tabuleiro[l+1][c+2]==' ')
			tabuleiro[l+1][c+2]='x';
		if(l+1 < 8 && c-2 >= 0 &&tabuleiro[l+1][c-2]==' ')
			tabuleiro[l+1][c-2]='x';		
		if(l-1 >= 0  && c+2 < 8 &&tabuleiro[l-1][c+2]==' ')
			tabuleiro[l-1][c+2]='x';
		if(l-1 >= 0 && c-2 >= 0 &&tabuleiro[l-1][c-2]==' ')
			tabuleiro[l-1][c-2]='x';		
		
	}	

}

int main()
{
	while (scanf("%s", &fen) != EOF) {
	
	int tamanho = strlen(fen);
	int linha = 0;
	int coluna = 0;
	
	for(linha=0; linha<8; linha++)
		for(coluna=0; coluna<8; coluna++)
			tabuleiro[linha][coluna]=' ';
	
	linha = 0;
	coluna = 0;
	
	//Montagem de tabuleiro
	for(i=0; i<tamanho; i++)
	{
		if(fen[i]=='/'){
			linha++;
			coluna=0;
		}	
		else if(fen[i]>='0' && fen[i]<='9')
			coluna+=(fen[i]-'0');
		else
			tabuleiro[linha][coluna++]=fen[i];	
	}

	for(linha=0; linha<8; linha++)
		for(coluna=0; coluna<8; coluna++)
			if(tabuleiro[linha][coluna]!=' ' && tabuleiro[linha][coluna]!='x')
				preencherCasas(linha, coluna);

	int casas=0;
	for(linha=0; linha<8; linha++) {
		for(coluna=0; coluna<8; coluna++) {
			if(tabuleiro[linha][coluna]==' ')
				casas++;
//			printf("%c", tabuleiro[linha][coluna]);
		}
//		printf("\n");
	}
	printf("%d\n", casas);
	}
	return 0;
}
