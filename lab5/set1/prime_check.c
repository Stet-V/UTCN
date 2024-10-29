#include <stdio.h>
#include <math.h>

int prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%lld", &n);
    printf("%d\n", prime(n));
    return 0;
}