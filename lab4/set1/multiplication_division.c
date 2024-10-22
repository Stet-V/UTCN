// 6.

#include <stdio.h>

int main() {
    int x, k;
    scanf("%d %d", &x, &k);
    printf("%d\n", x << k);
    printf("%d\n", x >> k);

    // double x;
    // int k;
    // scanf("%lf, %d", &x, &k);
    // printf("%.2lf\n", x * (1 << k));
    // printf("%.2lf\n", x / (1 << k));

    return 0;  
}