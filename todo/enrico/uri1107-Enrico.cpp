#include<stdio.h>

#define MAX 11234

int alt[MAX];

int main(){
	int a,c,i,count,mem,aux;
	while (scanf ("%d %d", &a,&c),(a!=0&&c!=0)){
		for (i=0;i<c;i++){
			scanf("%d",&alt[i]);
			alt[i]=(a-alt[i]);
		}
		for (i=1,mem=count=alt[0];i<c;i++){
			if (alt[i]>mem)
				count+=(alt[i]-mem);
			mem=alt[i];
		}
		printf("%d\n", count);
	}
	return 0;
}
