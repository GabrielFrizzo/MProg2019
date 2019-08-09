#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

#define MAX 112

int getw (ull n){
  int ans=(n==0);
  while (n){n/=10;ans++;}
  return ans; 
}
int main(){
  int n,m,i,j, counter=3;
  ull num[MAX][MAX];
  int w[MAX];
  scanf("%d",&n);	
  while(n--){
    memset(w, 0, sizeof(w));
    
    scanf("%d",&m);
    
    for (i=0;i<m;i++)
      for (j=0;j<m;j++){
        scanf("%llu",&num[i][j]);
        num[i][j]*=num[i][j];
	w[j]=max(w[j],getw(num[i][j]));
      }
    ++counter>4?printf("\nQuadrado da matriz #%d:\n",counter):printf("Quadrado da matriz #%d:\n",counter);
    for (i=0;i<m;i++){
      for (j=0;j<m;j++)
   	 printf("%s%*llu",j>0?" ":"",w[j],num[i][j]);
      printf ("\n");
    }
  }
  return 0;
}

