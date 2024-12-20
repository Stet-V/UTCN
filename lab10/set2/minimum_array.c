#include <stdio.h>

int minimum_array(int *a, int n) {
    if (n == 1)
        return a[0];
    int min = minimum_array(a, n - 1);
    return a[n - 1] < min ? a[n - 1] : min;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", minimum_array(a, n));
    return 0;
}