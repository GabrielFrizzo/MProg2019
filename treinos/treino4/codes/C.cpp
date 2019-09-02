#include<stdio.h>

int main(){
	int N,i,kg;
	double kgt=0,p,pt=0;
	char c;	
	
	scanf ("%d",&N);
	for (i=0;i<N;i++){
		scanf("%lf",&p);
		pt+=p;
		kg=1;
		getchar();
		while((c=getchar())!='\n')	
			if(c==' ')kg++;
		printf("day %d: %d kg\n",(i+1),kg);
		kgt+=kg;
	}
	pt/=N;
	kgt/=N;
	printf("%.2f kg by day\n",(kgt));
	printf("R$ %.2f by day\n",(pt));
}
