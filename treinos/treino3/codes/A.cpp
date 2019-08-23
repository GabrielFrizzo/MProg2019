#include<bits/stdc++.h>
#define MAX 41234

using namespace std;

int _rank[MAX], p[MAX];

int _find(int i){ return p[i]==i? i: p[i] = _find(p[i]);}
void _union(int i, int j){
	if( (i=_find(i)) == (j=_find(j))) return;
	if( _rank[i]<_rank[j] ) p[i]=j;
	else{
		p[j]=i;
		if(_rank[i]==_rank[j])
			_rank[i]++;
	} 
}

int main(){
	int i, n, m, t, x, y;
	set<int> list;
	
	scanf("%d", &t);
	
	for(int j=1; j<=t; j++){
		scanf("%d", &n);
		scanf("%d", &m);
		for(i=1; i<=n; i++){
			_rank[i] = 0;
			p[i] = i;
		}
		for(i=1; i<=m; i++){
			scanf("%d %d", &x, &y);
			_union(x,y);
		}
		list.clear();
		for(i=1; i<=n; i++){
			list.insert(p[i]);
		}
		printf("Caso #%d: ", j);
		if(list.size()==1)
			printf("a promessa foi cumprida\n");
		else
			printf("ainda falta(m) %d estrada(s)\n", list.size()-1);
		
	}
	
	return 0;
}
