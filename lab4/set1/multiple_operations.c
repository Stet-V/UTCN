// 5.

#include <stdio.h>

int main() {
    int x, k1, k2, k3;
    scanf("%d %d %d %d", &x, &k1, &k2, &k3);
    x |= (1 << k1);
    x &= ~(1 << k2);
    x ^= (1 << k3);
    printf("%d\n", x);
}