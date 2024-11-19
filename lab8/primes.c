#include <stdio.h>
#include <stdlib.h>

int prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int *primes(int n) {
    int *a = calloc(n + 1, sizeof(int));
    int k = 0;
    for (int i = 2; i <= n; i++)
        if (prime(i)) {
            k++;
            a[k] = i;
        }
    a[0] = k;
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = primes(n);
    for (int i = 1; i <= a[0]; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}