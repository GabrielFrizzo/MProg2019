#include<bits/stdc++.h>

using namespace std;

#define MAX 112345

int main (){
	int pontos[MAX];
	int distancias[MAX];
	int npontos,i,dist,soma;


	while(scanf("%d",&npontos)!=EOF){
		for (i=0,dist=0;i<npontos;i++){
			scanf("%d",&(distancias[i]));
			dist+=distancias[i];
			pontos[i]=0;
		}
		dist/=3;
		for (i=0;i<npontos;i++){
			if(pontos[i]==0){
			
			}
		}
		
		
	}
	
}
