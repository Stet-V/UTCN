#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char **functie(char **matrix, int n, int p, int masca);

int main() {
    


    FILE *pf = fopen("matrix.txt", "r");
    if (!pf)
        return -1;
    int m, n;
    char line[11];
    fgets(line, 11, pf);
    m = strlen(line) - 1;
    line[m] = '\0';
    char **modificat = calloc(m, sizeof(char *));
    for (int i = 0; i < m; i++) 
        modificat[i] = calloc(m + 1, sizeof(char));
    strcpy(modificat[0], line);
    for (int j = 1; j < m; j++) {
        fgets(modificat[j], m + 2, pf);
        modificat[j][m] = '\0';
    }
    fgets(line, 11, pf);
    n = strlen(line) - 1;
    line[n] = '\0';
    int k = m - n;
    char **original = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++) {
        original[i] = calloc(n + 1, sizeof(char));
        original[i][n] = '\0';
    }
    strcpy(original[0], line);
    for (int j = 1; j < n; j++)
        fgets(original[j], n + 2, pf);
    char **modificat1 = functie(modificat, m, 1, 33);
    for (int i = 0; modificat1[i] != NULL; i++) {
        printf("%s\n", modificat1[i]);
    }
    fclose(pf);
    return 0;
}

char **functie(char **matrix, int n, int p, int masca) { // p = 0 randuri, p = 1 coloane
    if (matrix == NULL)
        return NULL;
    if(masca == 0)
        return NULL;
    char **modificat = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++)
        modificat[i] = calloc(n + 1, sizeof(char));
    if (p == 0) {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if ((1 & masca) == 1) {
                strcpy(modificat[k], matrix[i]);
                k++;
            }
            masca >>= 1;
        }
        modificat[k] = NULL;
    } else {
        int k = 0;
        for (int i = 0; i < n; i++) {
            if ((1 & masca) == 1) {
                for (int j = 0; j < n; j++)
                    modificat[j][k] = matrix[j][i];
                k++;
            }
            masca >>= 1;
        }
        for (int i = 0; i < n; i++)
            modificat[i][k] = '\0';
    }
    return modificat;
}