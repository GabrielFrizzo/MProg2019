#include<stdio.h>

#define MAX 1<<14 

int neib(int n){
	int a=0,b=1,aux,pot=-1;
	aux = n;
	if (n == 0x2000)
		return 0;
	while(b==1 && a==0){
		a = aux %2;
		aux /=2;
		b = aux %2;
		pot ++;
	}
	b=2*b+a;
	if (b==0)aux = 1;
	else if (b==1)aux = 3;
	else if (b==3)aux = 2;
	else printf("ERROR\n");
	
	return ((n&(!(3<<pot)))|(aux<<pot));
	
	
}
int main(){
	int vp[MAX],vmp[MAX],vw[MAX];
	int n,potn,t,maxp,i,j;
	
	while(scanf("%d",&n)!=EOF){
		potn = 1<<n;
		for (i=1;i<=potn;i++){
			scanf("%d",&vw[i]);
		}
		for (i=1;i<=potn;i++){
			vp[i]=0;
			for(j=0;j<n;j++){
				t=i^(1<<j);
				vp[i]+=vw[t];
			}
		}
		t=n*(1<<(n-1)); 
		for (i=1;i<=potn;i++){
			vmp[i]=vp[i]+vp[neib(i)];
		}
		maxp=0;
		for (i=1;i<=t;i++){
			if (vmp[i]>maxp)
				maxp = vmp[i];
		}
		printf("%d\n",maxp);
	
	}
		
}
