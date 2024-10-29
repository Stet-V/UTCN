#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int totient(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++)
    if (gcd(n, i) == 1)
        s++;
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", totient(n));
    return 0;
}