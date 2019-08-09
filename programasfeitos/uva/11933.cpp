// Manipulação de bits, sugerido por HaHa. Fazemos o loop sobre n 31 vezes,
// inserindo 1 nas posições de a quando i indice do 1 é impar.
// É claro que b = a xor n, já que a e b nunca tem 1 na mesma posição,
// mas sempre que n possui 1, a ou b também o possui;

#include <cstdio>

int main() {
    int n, tmp, a, b, flag;

    while (scanf("%d", &n), n) {
        tmp = n;
        flag = 1;
        a = 0;
        for (int i = 0; i < 31; i++) {
            a |= (tmp%2 & flag)<<i;
            flag ^= tmp%2;
            tmp >>= 1;
        }
        b = a^n;
        printf("%d %d\n", a, b);
    }

    return 0;
}
