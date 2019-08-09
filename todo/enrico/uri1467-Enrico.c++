#include <stdio.h>

int main(){
	int a,b,c;
	while( scanf("%d %d %d",&a,&b,&c) != EOF){
		if (a != b && a != c)
			printf("A\n");
		else if ( b!= a && b!= c)
			printf("B\n");
		else if (b!=c && a != c)
			printf("C\n");
		else 
		printf("*\n");
	}
	return 0;
}
