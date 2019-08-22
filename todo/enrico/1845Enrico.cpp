#include <stdio.h>
#include <string.h>
#include <ctype.h>
int f(int c){
	return strchr("bjpsvxzBJPSVXZ",c)?(isupper(c)?'F':'f'):c;
}

int main(){
	int c,flag=0;
	while((c=getchar())!=EOF){
		c=f(c);
		if (c=='F'||c=='f'){
			if (!flag) {putchar(c);flag = 1;}
		}
		else{ putchar(c);flag=0;}

	}

}