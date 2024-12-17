#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char *a = calloc(1e6, sizeof(char));
    FILE *pf = fopen("..\\input\\words_in.txt", "r");
    if (!pf)
        return -1;
    int n = 0;
    while (fscanf(pf, "%c", &a[n]) == 1)
        n++;
    a[n] = '\0';
    int k = 0;
    char *temp = strtok(a, " .,\r\n");
    while (temp) {
        k++;
        temp = strtok(NULL, " .,\r\n");
    }
    printf("%d\n", k);
    free(a);
    fclose(pf);
    return 0;
}