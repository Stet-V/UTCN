#include <stdio.h>

int main() {
    float x;
    scanf("%f", &x);
    int k = x;
    int n = (k + 1) / 2;
    int s = n * n;
    printf("%d\n", s);
    return 0;
}
