#include <stdio.h>
#include <stdlib.h>

int is_symmetrical(int n, int **a) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (*(*(a + i) + j) != *(*(a + j) + i))
                return 0;
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int **a = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }
    printf("%d\n", is_symmetrical(n, a));
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
    return 0;
}