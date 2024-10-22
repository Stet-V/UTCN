#include <stdio.h>

int main() {
    double x;
    int b, k;
    scanf("%lf %d %d", &x, &b, &k);
    while (k > 0) {
        x *= b;
        printf("%d", (int)x);
        x -= (int)x;
        k--;
    }
}