#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenate(char *s1, char *s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    char *s = calloc(n1 + n2 + 1, sizeof(char));
    for (int i = 0; i < n1; i++)
        s[i] = s1[i];
    for (int i = 0; i < n2; i++)
        s[n1 + i] = s2[i];
    return s;
}

int main() {
    char s1[] = "abcdefgh";
    char s2[] = "ijklmnop";
    char s[strlen(s1) + strlen(s2) + 1];
    strcpy(s, s1);
    strcat(s, s2);
    s[strlen(s1) + strlen(s2)] = '\0';
    printf("%s\n", s);
    // char *s = concatenate(s1, s2);
    // printf("%s\n", s);
    // free(s);
    return 0;
}