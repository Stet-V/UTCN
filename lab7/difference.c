#include <stdio.h>

int difference(int *i1, int *i2) {
    return i1 - i2;
}

int main() {
    int a[100], i1, i2;
    scanf("%d %d", &i1, &i2);
    printf("%d\n", difference(&a[i1], &a[i2]));
    return 0;
}