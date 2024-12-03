#include <stdio.h>

long long int digit_sum(long long int n) {
    if (n < 10)
        return n;
    return n % 10 + digit_sum(n / 10);
}

int main() {
    long long int n;
    scanf("%lld", &n);
    printf("%lld\n", digit_sum(n));
    return 0;
}