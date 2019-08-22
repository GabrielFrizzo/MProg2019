#include<stdio.h>

int main(){
	int a,b,ra,rb,c,f=0;
	while(scanf("%d %d",&a,&b),(a!=0||b!=0)){
		f=c=0;
		while(a>0||b>0){
			ra=a%10+(f);
			rb=b%10;
			a/=10;
			b/=10;
			if((f=(ra+rb)/10)>0)c++;
			else f=0; 
		}
		if (c) printf("%d",c);
		printf("%s carry operation%s.\n",c>0?"":"No",c>1?"s":"");
		
	}


}