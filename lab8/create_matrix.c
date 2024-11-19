#include <stdio.h>
#include <stdlib.h>

double **create_matrix(int n, int m) {
    double **a = calloc(n, sizeof(double *));
    for (int i = 0; i < n; i++)
        a[i] = calloc(m, sizeof(double));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 1.0 / (i + j + 1);
    return a;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    double **a = create_matrix(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%lf ", a[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
    return 0;
}