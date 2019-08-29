#include<stdio.h>
#include<string.h>

#define MAX 112345

int bit[MAX],n;

void setbit(int i,int val){
	while(i<=n){
		bit[i]+=val;
		i+= (i) & (-i);
	}
}

int getbit(int i){
	int ans=0;
	while(i>0){
		ans +=bit[i];
		i-=i&-i;
	}
	return ans;
}

int main(){

	int T,C,p,q,v,op,i;
	
	scanf ("%d",&T);
	
	while(T--){
		scanf("%d %d",&n,&C);
        memset(bit, 0, sizeof(bit));

		while(C--){
			scanf("%d %d %d",&op,&p,&q);
			if (op){
				printf("%d\n",(getbit(q)-getbit(p-1)));
			}
			else{
				scanf("%d",&v);
				for(i=p;i<=q;i+=1)
					setbit(i,v);
			}
		}
	}
}
