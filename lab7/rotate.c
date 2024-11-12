#include <stdio.h>

void rotate(float *a, int n) {
    int temp = *a;
    for (int i = 0; i < n - 1; i++)
        *(a + i) = *(a + i + 1);
    *(a + n - 1) = temp;
}

int main () {
    int n;
    scanf("%d", &n);
    float a[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);
    rotate(a, n);
    for (int i = 0; i < n; i++)
        printf("%f ", a[i]);
    printf("\n");
    return 0;
}