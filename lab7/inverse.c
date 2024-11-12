#include <stdio.h>

void inverse(float *a, int n) {
    float *start = a;
    float *end = a + n - 1;
    while (start < end) {
        float temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    float a[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);
    inverse(a, n);
    for (int i = 0; i < n; i++)
        printf("%f ", a[i]);
    printf("\n");
    return 0;
}