// Ad Hoc. Problema sugerido pelo HaHa

#include <cstdio>

int main() {
    int a, b, tc;
    scanf("%d", &tc);

    while (tc--) {
        scanf("%d %d", &a, &b);

        a < b ? printf("%c\n", '<') : // ternário pro Zatesko ficar feliz
        a > b ? printf("%c\n", '>') :
        printf("%c\n", '=');
    }
    return 0;
}
