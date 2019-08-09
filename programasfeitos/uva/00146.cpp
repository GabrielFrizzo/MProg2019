// Implementado usando next_permutation, sugestão do HaHa. O problema aqui é utilizar char[] e string,
// já que scanf e printf não aceitam strings do C++.

#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

int main() {
    char s[51];
    while (scanf("%s", s), strcmp(s, "#") != 0) {
        string perm = (string)s;
        next_permutation(perm.begin(), perm.end()) ?
            printf("%s\n", perm.c_str()) :
            printf("No Successor\n");
    }

    
    return 0;
}
