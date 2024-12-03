#include <stdio.h>

int is_ascending(int *a, int n) {
    if (n <= 1)
        return 1;
    if (a[n - 1] < a[n - 2])
        return 0;
    return is_ascending(a, n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", is_ascending(a, n));
    return 0;
}