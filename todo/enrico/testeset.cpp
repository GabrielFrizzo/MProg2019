#include<bits/stdc++.h>

using namespace std;

typedef struct 
{
    int xi,yi,xf,yf;    
}buraco;

#define MAX 1123

buraco b[MAX];

int nothole(int xi, int yi, int nextxi, int nextyi,int h){
    int i;
    for (i=0;i<h;i++){
        if (yi>b[i].yi&&yi<b[i].yf&&((xi==b[i].xi&&nextxi<=b[i].xf)||(xi==b[i].xf&&nextxi>=b[i].xi))){
            return 0;
        }
        else if (xi>b[i].xi&&xi<b[i].xf&&((yi==b[i].yi && nextyi<=b[i].yf)||(yi==b[i].yf&&nextyi>=b[i].yi))){
            return 0;
        }
    }
    return 1;
}

int exploracaminhos(int xi, int yi, int xf, int yf, int ix, int iy,int px, int py, int h){
    int dp[MAX][MAX],i,j;
    dp[xi][yi]=1;
    if (xi==xf&&yi==yf)
        return 1;
    for(i=xi+ix;i!=xf+ix;i+=ix)
        if(nothole(i,yi,i-ix,yi,h))
            dp[i][yi]=dp[i-ix][yi];
        else{
            dp[i][yi]=0;
        }
    for (j = yi+iy; j!= yf+iy; j+=iy)
        if (nothole(xi,j,xi,j-iy,h))
            dp[xi][j]=dp[xi][j-iy];
        else{
            dp[xi][j]=0;
        }

    for(i=xi+ix;i!=xf+ix;i+=ix)
        for (j = yi+iy; j!= yf+iy; j+=iy){
            dp[i][j]=nothole(i,j,i-ix,j,h)*dp[i-ix][j]+nothole(i,j,i,j-iy,h)*dp[i][j-iy];
            //printf("%d %d %d %d %d %d %d\n",i,j,i+ix,j+iy, xf,yf,dp[i][j]);
            
        }

    for(i=xf+ix;i!=xi;i-=ix){
        for (j = yi; j!= yf+iy; j+=iy){
            printf("%5d ",dp[i][j]);
        }
        printf("\n");
    }

            
    return dp[xf][yf];

    
}


int main(){
    int n,m,h,count,xi,yi,xf,yf,q,px,py,i;

    while(scanf("%d %d %d",&m,&n,&h)!=EOF){
        for (i=0;i<h;i++)
            scanf("%d %d %d %d",&b[i].xi,&b[i].yi,&b[i].xf,&b[i].yf);
        scanf("%d",&q);
        for (i=0;i<q;i++){
            scanf("%d %d %d %d",&xi,&yi,&xf,&yf);
            px=(xf-xi)*(-2*(xi>xf)+1);
            py=(yf-yi)*(-2*(yi>yf)+1);
            count=exploracaminhos(xi,yi,xf,yf,((xi<=xf)?1:-1),(yi<=yf)?1:-1,px,py,h);
            printf("%d\n",count%(10*10*10*10*10*10*10*10*10+7));
        }
        printf("\n");

    }





}