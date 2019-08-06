/** Similar ao 1030, mas k varia. Para encontrar os k primos, foi criado um crivo de erastótenes **/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000


vector<int> erastSieve()
{
    vector<int> primes;
    bool sieve[MAX];
    memset(sieve, true, sizeof(sieve));

    for (int i = 2; i < MAX; i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
            for (int j = 2*i; j < MAX; j+=i) 
                sieve[j] = false;
        }
    }
    
    return primes;
}
vector<int> primes = erastSieve();

int m(int n)
{
    int result = 1;
    for(int i = 2; i <= n; i++)
    {
        result = ( result + primes[n-i]-1 ) % i + 1; // Aqui i vale n para cada iteração 
    }
    return result;
}


int main()
{
    int n;
    scanf("%d", &n);
    while(n != 0)
    {
        printf("%d\n", m(n));
        scanf("%d", &n);
    }


    return 0;
}
