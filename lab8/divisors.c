#include <stdio.h>
#include <stdlib.h>

int *divisors(int n) {
    int *a = malloc((n / 2 + 1) * sizeof(int));
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            k++;
            a[k] = i;
        }
    }
    a[0] = k;
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = divisors(n);
    for (int i = 1; i <= a[0]; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}