#include <stdio.h>

int main(){
	int n,pm,p,count,odd=0,flag=1;
	while(scanf("%d",&n),n!=0){
		count=pm=odd=0;
		flag=1;
		while(n--){
			scanf("%d",&p);
			if (p) count=flag=0;
			else {flag?odd=++count:++count;}
			if (count==2){pm++;flag?odd=count=0:count=0;}
		}
		printf("%d\n",p?pm:((odd==1)&&(count==1))?pm+1:pm);
	}
	return 0;

}