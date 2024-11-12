#include <stdio.h>

float *min_pointer(float *a, int n) {
    float *pmin = a;
    for (int i = 1; i < n; i++) {
        if (a[i] < *pmin) {
            pmin = &a[i];
        }
    }
    return pmin;
}

int main() {
    int n;
    scanf("%d", &n);
    float a[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);
    float *pmin = min_pointer(a, n);
    printf("%f\n", *pmin);
    return 0;
}