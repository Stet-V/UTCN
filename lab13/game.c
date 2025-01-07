#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n, m;
    char a[50][50];
} state;

void display(state x) {
    for (int i = 0; i < x.n; i++) {
        for (int j = 0; j < x.m; j++)
            printf("%c", x.a[i][j]);
        printf("\n");
    }
}

state afterT(state x, long long int T) {
    for (int i = 0; i < x.n; i++)
        for (int j = 0; j < x.m; j++) {
            if (x.a[i][j] >= '1' && x.a[i][j] <= '9') {
                int t = x.a[i][j] - '0';
                if (T >= t) {
                    for (int i2 = i - 1; i2 <= i + 1; i2++)
                        for (int j2 = j - 1; j2 <= j + 1; j2++)
                            if (i2 >= 0 && i2 < x.n && j2 >= 0 && j2 < x.m && x.a[i2][j2] == 't')
                                x.a[i2][j2] = '.';
                    x.a[i][j] = '.';
                } else {
                    x.a[i][j] -= T;
                }
            }
        }
    return x;
}

int checkT(char *row, int T) {
    int n = strlen(row);
    for (int i = 0; i < n; i++) {
        if (row[i] == 't') {
            int covered = 0;
            for (int j = i - 1; j <= i + 1; j++) {
                if (j >= 0 && j < n && row[j] >= '1' && row[j] <= '9') {
                    int bomb_T = row[j] - '0';
                    if (bomb_T <= T) {
                        covered = 1;
                        break;
                    }
                }
            }
            if (!covered) 
                return 0;
        }
    }
    return 1;
}

int binary_search(char *row, int a, int b) {
    if (a > b)
        return -1;
    int mid = a + (b - a) / 2;
    if (checkT(row, mid)) {
        int res = binary_search(row, a, mid - 1);
        return (res != -1) ? res : mid;
    } else
        return binary_search(row, mid + 1, b);
}

int minT(char *row) {
    int m = strlen(row);
    int bombs_T[50];
    int bomb_count = 0;
    for (int i = 0; i < m; i++)
        if (row[i] >= '1' && row[i] <= '9')
            bombs_T[bomb_count++] = row[i] - '0';
    if (bomb_count == 0) {
        for (int i = 0; i < m; i++)
            if (row[i] == 't') 
                return -1;
        return 0;
    }
    int max_T = 0;
    for (int i = 0; i < bomb_count; i++) {
        if (bombs_T[i] > max_T) {
            max_T = bombs_T[i];
        }
    }
    return binary_search(row, 0, max_T);
}

int canDestroy(state x) {
    for (int i = 0; i < x.n; i++) {
        for (int j = 0; j < x.m; j++) {
            if (x.a[i][j] == 't') {
                int covered = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < x.n && nj >= 0 && nj < x.m && x.a[ni][nj] >= '1' && x.a[ni][nj] <= '9') {
                            covered = 1;
                            break;
                        }
                    }
                    if (covered) break;
                }
                if (!covered) return 0;
            }
        }
    }
    return 1;
}

int maxRemoved(state x) {
    int max = 0;
    int positions[50][2], count = 0;
    for (int i = 0; i < x.n; i++) {
        for (int j = 0; j < x.m; j++)
            if (x.a[i][j] >= '1' && x.a[i][j] <= '9') {
                positions[count][0] = i;
                positions[count][1] = j;
                count++;
            }
    }
    for (int mask = 0; mask < (1 << count); mask++) {
        state temp = x;
        int removed = 0;
        for (int b = 0; b < count; b++)
            if (mask & (1 << b)) {
                int i = positions[b][0];
                int j = positions[b][1];
                temp.a[i][j] = '.';
                removed++;
            }
        if (canDestroy(temp))
            if (removed > max)
                max = removed;
    }
    return max;
}

int main() {
    FILE *pf = fopen("../input/inputA3.txt", "r");
    if (!pf)
        return -1;
    state x;
    fscanf(pf, "%d %d", &x.n, &x.m);
    for (int i = 0; i < x.n; i++)
        for (int j = 0; j < x.m; j++)
            fscanf(pf, " %c", &x.a[i][j]);

    display(x);
    int result = maxRemoved(x);
    if (result > 0) 
        printf("%d\n", result);
    else
        printf("Impossible\n");
    fclose(pf);
    return 0;
}