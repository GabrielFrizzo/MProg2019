#include <stdio.h>

int main(){
	int a,b,c;
	while( scanf("%d %d %d",&a,&b,&c) != EOF){
		printf("%s\n",a==b?c==a?"*":"C":a==c?"B":"A");
	}
	return 0;
}
