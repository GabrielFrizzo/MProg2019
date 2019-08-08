#include<stdio.h>

int main()
{
	
	int soma_max;
	int tam;
	int dist[112345];
	int p1, p2, p3, soma1, soma2;
	int qt, i;
	int paradaP1, paradaP2, paradaP3;
	

	while(scanf("%d", &tam)!=EOF)
	{
		soma_max=0;
		for(i=0; i<tam; i++){
			scanf("%d", &dist[i]);
			soma_max+=dist[i];
		}
        if (soma_max % 3) {printf("0\n");continue;}
		soma_max/=3;
        qt = 0;
		p1 = 0;
		p2 = 0;
		soma1=0;
		while(soma1<soma_max)
			soma1+=dist[p2++];
  //      printf("p2: %d\n", p2);
		p3=p2;	
		soma2=0;
		while(soma2<soma_max)
			soma2+=dist[p3++];
//        printf("p3: %d\n", p3);
//		soma3=0;	
//		for(i=p3; i<tam; i++)
//			soma3+=dist[i];

		paradaP1 = p2;
		paradaP2 = p3;
		paradaP3 = p1;
		while(p1!=paradaP1 && p2!=paradaP2 && p3!=paradaP3)
		{
//            printf("%d %d\n", soma1, soma2);
			if(soma1 == soma2 && soma1 == soma_max)
				qt++;
			soma1-=dist[p1];
//			soma3+=dist[p1];
			p1++;
			if(p1==tam)
				p1 = 0;
			while(soma1<soma_max)
			{
				soma1+=dist[p2];
				soma2-=dist[p2];
				p2++;
				if(p2==tam)
					p2=0;
			}
			while(soma2<soma_max)
			{
				soma2+=dist[p3];
//				soma3-=dist[p3];
				p3++;
				if(p3==tam)
					p3=0;
			}	

		}
		printf("%d\n", qt);
	}
	
	return 0;
}
