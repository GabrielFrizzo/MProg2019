#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long int n, res = 1;
    scanf("%lld", &n);

    while (n) {
        if (n%2) {
            res*=2;
        }
        n >>= 1;
    }

    printf("%lld\n", res);
    return 0;
}
