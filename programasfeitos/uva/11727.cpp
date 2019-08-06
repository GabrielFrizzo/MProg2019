// Sort facilita nesse caso

#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc, v[3];
    scanf("%d", &tc);

    for (int i = 1; i <= tc; i++) {
        scanf("%d %d %d", &v[0], &v[1], &v[2]);

        sort(v, v+sizeof(v)/sizeof(int));
        printf("Case %d: %d\n", i, v[1]);
    }

    return 0;
}
