#include <stdio.h>

void min_max(float *a, float *pmin, float *pmax, int n) {
    for (int i = 0; i < n; i++) {
        if (*pmin > a[i])
            *pmin = a[i];
        if (*pmax < a[i])
            *pmax = a[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    float a[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);
    float min = a[0], max = a[0];
    min_max(a, &min, &max, n);
    printf("%f %f\n", min, max);
    return 0;
}