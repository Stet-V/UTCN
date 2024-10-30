#include <stdio.h>

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

int main() {
    int na, nb;
    scanf("%d", &na);
    int a[na];
    for (int i = 0; i < na; i++)
        scanf("%d", &a[i]);
    scanf("%d", &nb);
    int b[nb];
    for (int i = 0; i < nb; i++)
        scanf("%d", &b[i]);
    int c[na + nb];
    for (int i = 0; i < na + nb; i++)
        c[i] = 0;
    int n = multiply(na, a, nb, b, c);
    for (int i = n - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
    return 0;
}