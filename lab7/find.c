#include <stdio.h>

float *find(float *a, int n, float x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x)
            return &a[i];
    }
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);
    float a[n];
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);
    float x;
    scanf("%f", &x);
    if (find(a, n, x))
        printf("%d\n", find(a, n, x) - a);
    else
        printf("NULL\n");
    return 0;
}