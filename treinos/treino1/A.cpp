#include<bits/stdc++.h>

using namespace std;

int main (){
	int a , b , q , r;
	scanf("%d %d",&a,&b);
	q = a/b;
	r = a%b;
	if (r<0 && b>0){
	  q--;
	  r+=b;
	}
	else if (r<0 && b<0){
	  q++;
	  r-=b;
	}

	printf("%d %d\n",q,r); 
	return 0;
}
