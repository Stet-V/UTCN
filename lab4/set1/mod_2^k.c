#include <stdio.h>

int main() {
    int x, k;
    scanf("%d %d", &x, &k);
    printf("%d\n", x & ((1 << k) - 1));
}