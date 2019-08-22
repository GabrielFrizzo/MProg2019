#include <stdio.h>

#define MAX 1123


int s[MAX];
int c=1;
int main(){
	int n,count=0,m=0,q,head;
	while(scanf("%d",&n),n!=0){
		while ((scanf("%d",&q)),(q!=0)){
			while(q>count){head=(s[c++]=++count);}
			m++;
			if (q!=s[--c]) { 
				printf("No\n",q,s[c]);
				for (int i=m;i<n;i++)
					scanf("%d",&q);
				m=0;
				count=0;
				c=1;
			}
			else if (m==n){
				m=0;
				printf("Yes\n");
				count=0;
				c=1;
			}
		}
		printf("\n");				
	}
}