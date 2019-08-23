#include<stdio.h>
#include<string.h>

#define MAX 112345

unsigned int bit[MAX],p[MAX],n;

void setbit(int i,int val){
	int j=0;
	while(i<=n){
		bit[i]+=(val+0*val);
		i+= (i) & (-i);
		j++;
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
		for (i=0;i<n;i++)
			bit[i]=0;
		while(C--){
			scanf("%d %d %d",&op,&p,&q);
			if (op){
				printf("%d\n",(getbit(q)-getbit(p-1)));
			}
			else{
				scanf("%d",&v);
				for(i=p+1;i<=q;i+=1)
					setbit(i,v);
				//if(!(q%2)) setbit(q,v);
			}
		}
	}
}
