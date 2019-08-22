#include<stdio.h>
#include<string.h>

int main(){
	char d,n,t=0;
	while (d=getchar()){
		n=getchar();n=getchar();
		if (n=='0')n=getchar();
		if (n=='\n')break;
		else if (n!=d&&n!=' '&& (n!='0'||t!=0) ){
				printf("%c",n);
				t=1;
			}
		while (n=getchar(),n!='\n'){
			if (n!=d&&n!=' '&& (n!='0'||t!=0) ){
				printf("%c",n);
				t=1;
			}
		}
		printf("%s\n",t?"":"0");
		t=0;
	}
	return 0;
}
