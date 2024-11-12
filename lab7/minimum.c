#include <stdio.h>

void minp(float *p, float x) {
    if (*p > x)
        *p = x;
}

int main() {
    int n;
    scanf("%d", &n);
    float a[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);
    float min = a[0];
    for (int i = 1; i < n; i++)
        minp(&min, a[i]);
    printf("%f\n", min);
    return 0;
}