#include <stdio.h>

int all_digits_odd(long long int n) {
    if (n <= 9) return n % 2 == 1;
    if (n % 2 == 0)
        return 0;
    return all_digits_odd(n / 10);
}

int main() {
    long long int n;
    scanf("%lld", &n);
    printf("%d\n", all_digits_odd(n));
    return 0;
}