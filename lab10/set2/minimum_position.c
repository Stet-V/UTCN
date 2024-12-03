#include <stdio.h>

int minimum_position(int *a, int n) {
    if (n == 1)
        return 0;
    int min = minimum_position(a, n - 1);
    return a[n - 1] < a[min] ? n - 1 : min;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", minimum_position(a, n));
    return 0;
}