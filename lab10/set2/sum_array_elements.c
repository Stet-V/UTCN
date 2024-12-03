#include <stdio.h>

int sum_array_elements(int *a, int n) {
    if (n == 0)
        return 0;
    return a[n - 1] + sum_array_elements(a, n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", sum_array_elements(a, n));
    return 0;
}