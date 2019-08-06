/** Programação dinâmica: m(n, k) = (m(n-1,k) + k) mod n + 1 **/

#include <stdio.h>

int m(int n, int k)
{
    int result = 1;
    for(int i = 2; i <= n; i++)
    {
        result = ( result + k-1 ) % i + 1; // Aqui i vale n para cada iteração 
    }
    return result;
}

int main()
{
    int nc, n, k;
    scanf("%d", &nc);

    for(int i=1; i <= nc; i++)
    {
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i, m(n, k));
    }


    return 0;
}
