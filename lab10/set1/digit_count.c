#include <stdio.h>

long long int digit_count(long long int n) {
    if (n < 10)
        return 1;
    return 1 + digit_count(n / 10);
}

int main() {
    long long int n;
    scanf("%lld", &n);
    printf("%lld\n", digit_count(n));
    return 0;
}