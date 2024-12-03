#include <stdio.h>

int contains_digit(long long int n, int k) {
    if (k == n % 10)
        return 1;
    if (n < 10)
        return 0;
    return contains_digit(n / 10, k);
}

int main() {
    long long int n;
    int k;
    scanf("%lld %d", &n, &k);
    printf("%d\n", contains_digit(n, k));
    return 0;
}