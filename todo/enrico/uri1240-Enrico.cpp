# include <stdio.h>

int main(){
	int a,b,n,flag;
	scanf("%d",&n);

	while(n--){
		scanf("%d %d",&a,&b);
		flag=1;
		while(b>0){
			if(b%10==a%10){a/=10;b/=10;}
			else flag=(b=0);
		}
		printf("%sencaixa\n",flag?"":"nao ");
	}
	return 0;

}
