#include <stdio.h>
#include "array_utils.h"

int main() {
    int n;
    scanf("%d", &n);
    float a[n];
    read(n, a);
    display(n, a);
    printf("%f\n", minval(n, a));
    printf("%d\n", min(n, a));
    printf("%f\n", sum(n, a));
    inverse(n, a);
    display(n, a);
    bubble(n, a);
    display(n, a);
    return 0;
}