#include <stdio.h>

int main() {
    int x, k;
    scanf("%d %d", &x, &k);

    // 1.
    if (x & (1 << k))
        printf("active\n");
    else
        printf("inactive\n");
    
    // 2.
    printf("%d\n", x | (1 << k));

    // 3.
    printf("%d\n", x & ~(1 << k));

    // 4.
    printf("%d\n", x ^ (1 << k));

    return 0;
}