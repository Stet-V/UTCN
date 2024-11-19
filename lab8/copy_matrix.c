#include <stdio.h>
#include <stdlib.h>

int **copy_matrix(int n, int m, int a[n][m]) {
    int **b = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        b[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
            b[i][j] = a[i][j];
    }
    return b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    int **b = copy_matrix(n, m, a);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
        free(b[i]);
    free(b);
    return 0;
}