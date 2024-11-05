#include <stdio.h>

int digits(long long int x, int a[]) {
    int r = 0;
    do {
        a[r] = x % 10;
        x /= 10;
        r++;
    } while (x > 0);
    return r;
}

int multiply(int na, int a[], int nb, int b[], int c[]) {
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= 10) {
                c[i + j + 1] += c[i + j] / 10;
                c[i + j] %= 10;
            }
        }
    }
    int r = na + nb;
    while (c[r - 1] == 0)
        r--;
    return r;
}

int large_factorial(int n, int a[]) {
    int na = 1;
    for (int i = n; i >= 2; i--) {
        int t[1000] = {0};
        int nt = digits(i, t);
        int product[1000] = {0};
        na = multiply(na, a, nt, t, product);
        for (int j = 0; j < na; j++)
            a[j] = product[j];
    }
    return na;
}

int main() {
    int n, a[1000] = {1};
    scanf("%d", &n);
    int na = large_factorial(n, a);
    for (int i = 0; i < na; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}