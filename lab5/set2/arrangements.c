#include <stdio.h>

long long int arrangements(int n, int k) {
    long long int r = 1;
    for (int i = 1; i <= k; i++)
        r *= n - i + 1;
    return r;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%lld\n", arrangements(n, k));
    return 0;
}