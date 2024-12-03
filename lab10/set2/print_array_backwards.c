#include <stdio.h>

void print_array_backwards(int *a, int n) {
    if (n == 0)
        return;
    print_array_backwards(a + 1, n - 1);
    printf("%d ", *a);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    print_array_backwards(a, n);
    return 0;
}