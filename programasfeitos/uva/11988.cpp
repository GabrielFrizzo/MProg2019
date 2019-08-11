// Uso de list da STL, de acordo com dica do HaHa(2.2)

#include <cstdio>
#include <list>
using namespace std;

int main() {
    list<char> result; auto it=result.begin();
    char input[112345];
    while (scanf("%s", input) != EOF) {
        result.clear();
        it = result.begin();
        for (int i=0; input[i]; i++) {
            if (input[i] == '[') {it=result.begin();}
            else if (input[i] == ']') {it=result.end();}
            else {
                result.insert(it, 1, input[i]);
            }
        }
        for (auto it=result.begin(); it!=result.end(); it++)
            printf("%c", *it);
        printf("\n");
    }

    return 0;
}
