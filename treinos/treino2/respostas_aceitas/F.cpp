#include <bits/stdc++.h>

int main() {
    int size;
    int m[1<<15], p[1<<15];

    while (scanf("%d", &size) != EOF) {
        memset(p, 0, 1<<15);
        for (int i=0; i<1<<size; i++) {
            scanf("%d", &m[i]);
        }

        for (int i=0; i<1<<size; i++) {
            for (int shift=0; shift < size; shift++) {
                p[i] += m[i^(1<<shift)];
            }
        }
        int max=0;
        for (int i=0; i<1<<size; i++) {
            for (int shift=0; shift < size; shift++) {
                if (p[i]+p[i^(1<<shift)] > max) {
                    max = p[i]+p[i^(1<<shift)]; 
                }
            }
        }
        printf("%d\n", max);
    }

    return 0;
}
