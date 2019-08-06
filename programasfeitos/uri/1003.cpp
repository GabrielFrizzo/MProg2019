#include <stdio.h>

int main()
{
    int a, b;
    if (scanf("%d", &a) == 2) {return(1);};
    if (scanf("%d", &b) == 2) {return(1);};
    printf("SOMA = %d\n", a+b);
    return 0;
}
