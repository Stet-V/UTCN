#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int *dims, int n) {
    int **a = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = calloc(dims[i], sizeof(int));
        for (int j = 0; j < dims[i]; j++)
            a[i][j] = rand() % 10;
    }
    return a;
}

void print_matrix(int **a, int *dims, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < dims[i]; j++)
            printf("%d", a[i][j]);
        printf("\n");
    }
}

void delete_row(int **a, int *dims, int *n, int i) {
    free(a[i]);
    (*n)--;
    for (int k = i; k < *n; k++) {
        a[k] = a[k + 1];
        dims[k] = dims[k + 1];
    }
}

void delete_column(int **a, int *dims, int *n, int j) {
    for (int i = 0; i < *n; i++) {
        if ((j == 0) && (dims[i] == 1)) {
            delete_row(a, dims, n, i);
            i--;
        } else if (j < dims[i]) {
            for (int k = j; k < dims[i] - 1; k++) {
                a[i][k] = a[i][k + 1];
            }
            dims[i] -= 1;
        }
    }
}

void free_matrix(int **a, int *dims, int n) {
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
    free(dims);
}

int main() {
    int n;
    scanf("%d", &n);
    int *dims = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &dims[i]);
    int **a = create_matrix(dims, n);
    print_matrix(a, dims, n);
    int j;
    scanf("%d", &j);
    delete_column(a, dims, &n, j);
    print_matrix(a, dims, n);
    int i;
    scanf("%d", &i);
    delete_row(a, dims, &n, i);
    print_matrix(a, dims, n);
    free_matrix(a, dims, n);
    return 0;
}