# include <stdio.h>

int g(int n, int k){
	int nl;
	int value;
	if (n==1)
		return 0;
	else if (n<k && n>1)
		return (g(n-1,k)+k)%n;
	else if (k<=n){
		nl = n - (int)(n/k);
		value = g(nl,k)- n%k;
		while(value<0) value+=nl;
		return (int) (k*((value) % nl)/(k-1));
	}
}

int main (){
	int i=0,nc,n,k;
	scanf("%d",&nc);
	while (++i<=nc){
		scanf ("%d %d",&n,&k);
		printf ("Case %d: %d\n",i,(g(n,k)+1));
	}
	return 0;
}
