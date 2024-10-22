#include <stdio.h>

int main() {
    long long int a;
    int b, k = 0;
    scanf("%lld %d", &a, &b);
    do {
        k++;
        a = a / b;
    } while (a);
    printf("%d\n", k);
}