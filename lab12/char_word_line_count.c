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
    a = realloc(a, (n + 1) * sizeof(char));
    int char_count = 0, line_count = 0, word_count = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        if (!strchr(" .,\r\n", a[i]))
            char_count++;
        if (a[i] == '\n')
            line_count++;
    }
    char *temp = strtok(a, " .,\r\n");
    while (temp) {
        word_count++;
        temp = strtok(NULL, " .,\r\n");
    }
    printf("%d %d %d\n", char_count, line_count, word_count);
    free(a);
    fclose(pf);
    return 0;
}