#include<bits/stdc++.h>

using namespace std;


int main(){
	set <string> s;
	char str[212],c;
	int i=0;

	while ((c=getchar())!=EOF){
		if (isalpha(c))
			str[i++]=tolower(c);
		else if(i!=0){
			str[i]=0;
			s.insert(string(str));
			i=0;
		}
	}
	for (auto &j : s)
		printf("%s\n", j.c_str());
	return 0;

}