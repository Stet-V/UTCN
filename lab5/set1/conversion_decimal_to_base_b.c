#include <stdio.h>
#include <math.h>

int conversion(long long n, int b, int c[]) {
    int k = 0;
    do {
        c[k] = n % b;
        n = n / b;
        k++;
    } while(n);
    return k;
}

char digit_to_char(int x) {
    if (x < 10)
        return '0' + x;
    return 'A' + x - 10;
}

int main() {
    long long n;
    int c[100], b;
    scanf("%lld%d", &n, &b);
    int k = conversion(n, b, c);
    for (int i = k - 1; i >= 0; i--)
        printf("%c", digit_to_char(c[i]));
    printf("\n");
    return 0;
}