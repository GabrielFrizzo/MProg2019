// Usando nth_element, dada dica do HaHa. Este método coloca na n-ésima posição,
// o valor que estaria nesta posição caso o vetor fosse ordenado, mas não o ordena.
// Por isso, gasta tempo O(n), e não O(nlgn)

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int curr, i=0, result;
    int v[11234];
    while (scanf("%d", &curr) == 1) {
        v[i] = curr;
        nth_element(v, v+i/2, v+i+1);
        result = v[i/2];
        if (i % 2) {                             //quando o tamanho do vetor é par
            nth_element(v, v+i/2+1, v+i+1);      //devemos encontrar a media dos dois valores
            result += v[i/2+1];                  //no meio do vetor
            result /= 2;
        }
        printf("%d\n", result);
        i++;
    }

    return 0;
}
