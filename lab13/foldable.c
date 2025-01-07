#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int *a, int *b, int i, int j) {
    for (int k = i; k <= j; k++)
        printf("%d ", a[k]);
    printf("\n");
    for (int k = i; k <= j; k++)
        printf("%d ", b[k]);
}

int isFoldable(int *a, int n, int x, int k) {
    if (x == 0)
        for (int i = 0; i < k; i++)
            if (a[i] != a[2 * k - 1 - i])
                return 0;
    if (x == 1) 
        for (int i = 0; i < k; i++) 
            if (a[n - 2 * k + i] != a[n - 1 - i])
                return 0;
    return 1;
}

int canTransform(int *a, int n, int *b, int m, int depth, char *result) {
    if (n == m) {
        int equal = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                equal = 0;
                break;
            }
        }
        if (equal) return 1;
    }
    if (depth >= 2) return 0;
    for (int k = 1; k <= n / 2; k++) {
        if (isFoldable(a, n, 0, k)) {
            int new_n = n - k;
            int new_a[new_n];
            for (int i = k; i < n; i++)
                new_a[i - k] = a[i];
            if (canTransform(new_a, new_n, b, m, depth + 1, result)) {
                if (strlen(result) > 0)
                    sprintf(result + strlen(result), ", left %d", k);
                else
                    sprintf(result + strlen(result), "left %d", k);
                return 1;
            }
        }
        if (isFoldable(a, n, 1, k)) {
            int new_n = n - k;
            int new_a[new_n];
            for (int i = 0; i < new_n; i++)
                new_a[i] = a[i];
            if (canTransform(new_a, new_n, b, m, depth + 1, result)) {
                if (strlen(result) > 0)
                    sprintf(result + strlen(result), ", right %d", k);
                else
                    sprintf(result + strlen(result), "right %d", k);
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int n = 8, m = 4;
    // scanf("%d %d", &n, &m);
    int a[] = {1, 2, 3, 4, 4, 3, 2, 1}, b[] = {1, 2, 3, 4};
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &a[i]);
    // for (int i = 0; i < m; i++)
    //     scanf("%d", &b[i]);
    // display(a, b, 1, 2);
    // printf("%d\n", isFoldable(a, n, 1, 2));
    // printf("%d\n", isFoldable(b, m, 0, 1));
    char result[100];
    result[0] = '\0';
    if (canTransform(a, n, b, m, 0, result))
        printf("solution %s\n", result);
    else
        printf("Impossible\n");
    return 0;
}