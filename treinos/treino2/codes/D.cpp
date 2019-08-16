	#include <bits/stdc++.h>
using namespace std;

int main(){
	char c=5,p[50];
	int count=0, flag=0,i=0;

	while(true){
		while(c!='\n'){
			c=getchar();
			p[count]=c;
			count++;
			if(c=='#') return 0;
		}
	c = 6;
	count --;
	flag = next_permutation(p,p+count);

	
	if(flag){
		while(i<count){
			printf("%c",p[i++]);
		}
	i=0;
	}
	else
		printf("No Successor");

	printf("\n");
	count =0;
	}
}
