#include <stdio.h>

int main() {
    long long int a;
    int k = 0;
    scanf("%lld", &a);
    do {
        if (a % 2 == 1)
            k++;
        a = a / 2;
    } while (a);
    printf("%d\n", k);
}