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

int main() {
    int a[19];
    long long int x;
    scanf("%lld", &x);
    int n = digits(x, a);
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}