#include <stdio.h>
#include <stdlib.h>

long long int **pascal_triangle(int n) {
    long long int **a = calloc(n, sizeof(long long int *));
    for (int i = 0; i < n; i++) {
        a[i] = calloc(i + 1, sizeof(long long int));
        a[i][0] = a[i][i] = 1;
        for (int j = 1; j < i; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    long long int **a = pascal_triangle(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
    return 0;
}