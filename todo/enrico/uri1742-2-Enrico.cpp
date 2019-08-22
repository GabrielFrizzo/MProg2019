#include<stdio.h>


#define MAX 1123

unsigned int b[MAX][MAX];
unsigned int dp[MAX][MAX];
int n,m;


int exploracaminhos(int xi, int yi, int xf, int yf, int ix, int iy,int px, int py){
	int i,j;
	unsigned int jam = 10*10*10*10*10*10*10*10*10+7;
	dp[xi][yi]=1;
		
	if (xi==xf && yi==yf)
		return 1;
	for(i=xi+ix;i!=xf+ix;i+=ix)
		dp[i][yi]=b[i][yi]?ix>0?(b[i][yi]&8)==8?0:dp[i-ix][yi]:(b[i][yi]&2)==2?0:dp[i-ix][yi]:dp[i-ix][yi];
		
	for (j = yi+iy; j!= yf+iy; j+=iy)
		dp[xi][j]=b[xi][j]?iy>0?(b[xi][j]&4)==4?0:dp[xi][j-iy]:(b[xi][j]&1)==1?0:dp[xi][j-iy]:dp[xi][j-iy];
		
	
	
	for(i=xi+ix;i!=xf+ix;i+=ix)
		for (j = yi+iy; j!= yf+iy; j+=iy){
			dp[i][j]=((((b[i][j])?iy>0?((b[i][j])&4)==4?0:dp[i][j-iy]:((b[i][j])&1)==1?0:dp[i][j-iy]:dp[i][j-iy])
			          +((b[i][j])?ix>0?((b[i][j])&8)==8?0:dp[i-ix][j]:((b[i][j])&2)==2?0:dp[i-ix][j]:dp[i-ix][j]))%jam);
			
		}			
	/*for (j=n;j>=0;j--){
		for (i=0;i<=m;i++)
			printf("%2d ",b[i][j] );
			printf("\n");
	}*/
			
	return (int) dp[xf][yf];
	
}
int main(){
	int h,xi,yi,xf,yf,q,px,py,i,j,k;
	int count;
	while(scanf("%d %d %d",&m,&n,&h)!=EOF){
		for (i=0;i<n;i++)
			for (j=0;j<m;j++)
				b[i][j]=0;
		for (k=0;k<h;k++){
			
			scanf("%d %d %d %d",&xi,&yi,&xf,&yf);
			for (i=xi;i<=xf;i++)
				for (j=yi;j<=yf;j++){
					if (j>yi && j<yf){
						if (i==xi)  			b[i][j]+=2;
						else if (i==xf)	  		b[i][j]+=8;
						else if (i>xi&&i<xf)	b[i][j]+=10;
					}
					if (i>xi && i<xf){
						if(j==yi) 				b[i][j]+=1;
						else if (j==yf) 		b[i][j]+=4;
						else if (j>yi&&j<yf)	b[i][j]+=5;	
					}
				}
		}

		scanf("%d",&q);
		for (i=0;i<q;i++){
			scanf("%d %d %d %d",&xi,&yi,&xf,&yf);
			px=(xf-xi)*(-2*(xi>xf)+1);
			py=(yf-yi)*(-2*(yi>yf)+1);
			count=exploracaminhos(xi,yi,xf,yf,((xi<=xf)?1:-1),(yi<=yf)?1:-1,px,py);
			printf("%d\n",count);
		}
		printf("\n");

	}

}
/*
for (j=n;j>=0;j--){
				for (i=0;i<=m;i++)
					printf("%2d ",b[i][j] );
					printf("\n");
			}
			
				printf("\n");
			for (j=n-1;j>=0;j--){
					for (i=0;i<m;i++)
						printf("%2d ",dp[i][j] );
					printf("\n");
				}
				printf("\n");
		*/