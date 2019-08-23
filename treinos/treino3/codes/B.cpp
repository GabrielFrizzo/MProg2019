#include<stdio.h>

int main()
{
	double H, Y, U, D, F, L, T;
	int dia;	
	while(scanf("%lf %lf %lf %lf", &H, &U, &D, &F), H!=0)
	{
		L=U*F/100;
		dia = 0;
		U+=L;
		T=0;
		while(U>=0 && T>=0){
			dia++;
			U-=L;
			T+=U;
			if(T>H)
				break;
			T-=D;
		}
		if(T>=H)
			printf("sucess on day %d\n", dia);
		else
			printf("failure on day %d\n", dia);
	}
	return 0;
}
