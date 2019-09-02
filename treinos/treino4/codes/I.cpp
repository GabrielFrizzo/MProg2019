#include<bits/stdc++.h>

using namespace std;

map <int,vector<int>> nk;
map <int,vector<int>> kn;
map <int,int> visitado;
int _queue[1123456],qi=0,qf=0;

int _enqueue(int i){
	return _queue[qf++]=i;
}
int _dequeue(void){
	if(qi<qf)return _queue[qi++];
	return 0;
}	
int _emptyqueue(void){
	return qf==qi;
}

int menorcusto(int n){
	int custo = 0,elem;
	
	for (auto i:nk[1])
		_enqueue(i);
	while(!_emptyqueue()){
		elem = _dequeue();
		custo++;
		for (auto j:kn[elem]){
			if (j==n) return custo;
			for (auto k:nk[j])
				if (visitado.find(k)!=visitado.end()){
					visitado[k]=1;					
					_enqueue(k);
				}
		}
	}
	return custo;
}

int main(){
	int n,k,i,e;
	char c;

	scanf ("%d %d",&n,&k);
	for(i=0;i<n;i++){
		while(scanf("%d",&e),(c=getchar()),c==' '){
			nk[e].push_back(i);
			kn[i].push_back(e);					
		}	
		nk[e].push_back(i);
		kn[i].push_back(e);					
	}
	printf("%d\n",menorcusto(n));
}
