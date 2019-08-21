// UVA 146 - IDCodes - This code solve the cited problem using on his core STL's "next_permutation"
// Basically the function returns True if a string have a next alphabetical string with the same numbers of letters
// and False if there is no next element possible.
// Guide: http://www.cplusplus.com/reference/algorithm/next_permutation/
 #include <bits/stdc++.h>
using namespace std;

int main(){
	char c=5,p[50];
	int count=0,flag=0,i=0;

	// Start of the procedure
	while(true){
		// Wait untill a '\n'
		// I am pretty sure that we have a better solution for this
		while(c!='\n'){
			c=getchar();
			p[count]=c;
			count++;
			if(c=='#') return 0;
		}
	// Erase the '\n' in c
	c = 6;
	// Decrease count 
	count --;

	// p always will receive the next string possible
	// flag indicates if that string is valid or not
 	// If we are seeing the last case in p, after the
	// function p will be the first case with the letters
	// but the flag will return false;
	flag = next_permutation(p,p+count);

	// Testing the flag
	// if True prints the next element
	if(flag){
		while(i<count){
			printf("%c",p[i++]);
		}
	i=0;
	}
	// if false, prints No Successor (double "c", plz!)
	else
		printf("No Successor");

	printf("\n");
	count =0;
	}
}
