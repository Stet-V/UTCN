#include <stdio.h>
#include <stdlib.h>

double **create_matrix(int n, int m) {
    double **a = calloc(n, sizeof(double *));
    for (int i = 0; i < n; i++) {
        a[i] = calloc(m, sizeof(double));
        for (int j = 0; j < m; j++)
            a[i][j] = 1.0 / (i + j + 1);
    }
    return a;
}

double **transpose(double **a, int n, int m) {
    double **b = calloc(m, sizeof(double *));
    for (int i = 0; i < m; i++) {
        b[i] = calloc(n, sizeof(double));
        for (int j = 0; j < n; j++)
            b[i][j] = a[j][i];
    }
    return b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    double **a = create_matrix(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%f ", a[i][j]);
        printf("\n");
    }
    printf("\n");
    double **b = transpose(a, n, m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%f ", b[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
    for (int i = 0; i < m; i++)
        free(b[i]);
    free(b);
    return 0;
}