#include <bits/stdc++.h>

#define MAX 1123

using namespace std;

int N,M,K,L;
char t[MAX],a,b;
int i=0,flag=1;

int main(){

    while(scanf("%d %d",&N,&M)!=EOF){
        getchar();
        while(N--){
            scanf(" %c",&t[i++]); 
            printf("%c",t[i-1]);
        }

        flag = 1;
        while(M--){
            scanf("%d %d",&K,&L);
            printf("%d %d\n",K,L);
            if(t[K]!=t[L]){
                flag = 0;
                printf("N\n");
                break;
            }
        
        }
        i=0;
        if(flag)
            printf("Y\n");
    }

return 0;
}
