#include <stdio.h>
#include "functions.h"

int main() {
    int n;
    scanf("%d", &n);
    float a[n];
    read(n, a);
    print(n, a);
    printf("%f\n", minval(n, a));
    printf("%d\n", min(n, a));
    printf("%f\n", sum(n, a));
    inverse(n, a);
    print(n, a);
    bubble(n, a);
    print(n, a);
    return 0;
}