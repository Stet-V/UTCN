#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int totient(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++)
        if (gcd(n, i) == 1)
            s++;
    return s;
}

int *euler_totient(int n) {
    int *phi = calloc(n + 1, sizeof(int));
    phi[0] = n;
    for (int i = 1; i <= n; i++) {
        phi[i] = totient(i);
    }
    return phi;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = euler_totient(n);
    for (int i = 1; i <= a[0]; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}