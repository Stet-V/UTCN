#include <stdio.h>

long long int combinations(int n, int k) {
    long long int r = 1;
    for (int i = 1; i <= k; i++)
        r = r * (n - i + 1) / i;
    return r;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%lld\n", combinations(n, k));
    return 0;
}