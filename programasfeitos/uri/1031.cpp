/** Semelhante ao uri1030, se fizermos i = i-1, a situação se torna a mesma, e o m a ser alcançado se torna 12.
 *  No entanto, desta vez a variável a ser encontrada é k, e m é dado.**/

#include <stdio.h>

int m(int n, int k)
{
    int result = 1;
    for(int i = 2; i <= n; i++)
    {
        result = ( result + k-1 ) % i + 1;
    }
    return result;
}

int k(int n)
{
    int attempt = 1;
    while(m(n, attempt) != 12)
    {
        attempt++;
    }
    return attempt;
}

int main()
{
    int n;
    scanf("%d", &n);
    do
    {
        printf("%d\n", k(n-1)); // n-1 aqui é por iniciarmos sem o elemento 1, como dito no comentário inicial
        scanf("%d", &n);
    } while(n!= 0);


    return 0;
}
