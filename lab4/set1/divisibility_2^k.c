#include <stdio.h>

int main() {
    int x, k;
    scanf("%d %d", &x, &k);
    if ((x & ((1 << k) - 1)) == 0)
        printf("true\n");
    else
        printf("false\n");
}