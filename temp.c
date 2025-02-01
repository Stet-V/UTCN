#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findmax(long long int **a, int B, int L, int *maxi, int *maxj);
int chartoindex(char c, int B);

int main() {
    int B, L, N, K;
    FILE *pf = fopen("inputA.txt", "r");
    if (!pf) {
        printf("File not found\n");
        return 1;
    }
    fscanf(pf, "%d %d %d %d\n", &B, &L, &N, &K);
    char a[B][L];
    for (int i = 0; i < B; i++)
        for (int j = 0; j < L; j++)
            a[i][j] = '.';
    int x, y;
    while(fscanf(pf, "%c%d ", &x, &y) == 2)
        a[chartoindex(x, B)][y - 1] = 'X';
    long long int **heatmap = calloc(B, sizeof(long long int *));
    for (int i = 0; i < B; i++)
        heatmap[i] = calloc(L, sizeof(long long int));
    scanf("%d", &K);
    while(K--) {
        long long int **heatmap = calloc(B, sizeof(long long int *));
            for (int i = 0; i < B; i++)
        heatmap[i] = calloc(L, sizeof(long long int));
        for (int i = 0; i < L; i++)
            for (int j = 0; j < B; j++)
            if (a[j][i] == 'X') {
                heatmap[j][i] = -1;
                for (int k = 0; k < B; k++)
                    for (int l = 0; l < L; l++)
                        if (heatmap[k][l] != -1) {
                            long long int temp = abs(j - k) > abs(i - l) ? abs(j - k) : abs(i - l);
                            heatmap[k][l] += temp;
                        }
            }
    int maxi, maxj;
    findmax(heatmap, B, L, &maxi, &maxj);
    a[maxi][maxj] = 'X';
    heatmap[maxi][maxj] = -1;
        for (int k = 0; k < B; k++)
            for (int l = 0; l < L; l++)
                if (heatmap[k][l] != -1) {
                    long long int temp = abs(maxj - k) > abs(maxi - l) ? abs(maxj - k) : abs(maxi - l);
                    heatmap[k][l] += temp;
                }
    }
    printf(" ");
    for (int i = 1; i <= L; i++)
        printf("%d", i % 10);
    printf("\n");
    for (int i = 0; i < B; i++) {
        printf("%c", 'A' + B - i - 1);
        for (int j = 0; j < L; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
    return 0;
}

int chartoindex(char c, int B) {
    return -(c - 'A' - B + 1);
}

void findmax(long long int **a, int B, int L, int *maxi, int *maxj) {
    *maxi = 0;
    *maxj = 0;
    for (int i = B - 1; i >= 0; i--)
        for (int j = 0; j < L; j++)
            if (a[i][j] > a[*maxi][*maxj]) {
                *maxi = i;
                *maxj = j;
            }
}