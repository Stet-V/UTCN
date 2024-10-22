#include <stdio.h>

int main() {
    long long int a;
    int b;
    scanf("%lld %d", &a, &b);
    do {
        printf("%d", a % b);
        a = a / b;
    } while (a);
}