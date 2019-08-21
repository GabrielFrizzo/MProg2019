#include <bits/stdc++.h>

using namespace std;

int main()
{
	set<string> dicionario;
	string palavra;
	char c;
	
	palavra="";	
	while(scanf("%c", &c)!=EOF)
	{
		c=tolower(c);
		if(isalpha(c))
			palavra+=c;
		else{
			if(palavra!="")
			{
				palavra+='\0';
				dicionario.insert(palavra);
			}
			palavra="";
		}
	}
	for(auto j: dicionario)
		printf("%s\n", j.c_str());
	return 0;
}
