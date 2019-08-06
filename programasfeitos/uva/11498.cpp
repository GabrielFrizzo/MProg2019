// Ad Hoc. Problema sugerido por HaHa

#include <cstdio>

int main() {
    int tc, x, y, qx, qy;

    while (scanf("%d", &tc), tc) {
        scanf("%d %d", &x, &y);
        while (tc--) {
            scanf("%d %d", &qx, &qy);

            if (qx == x || qy == y) {
                printf("divisa\n");
            }
            else {
                qy > y ? printf("%c", 'N') : printf("%c", 'S');
                qx > x ? printf("%c\n", 'E') : printf("%c\n", 'O');
            }
        }
    }

    return 0;
}
