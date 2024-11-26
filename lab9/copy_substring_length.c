#include <stdio.h>
#include <string.h>

void copy_substring(char *s, char *t, int a, int len) {
    for (int i = 0; i < len; i++)
        t[i] = s[a + i];
    t[len] = '\0';
}

int main() {
    char s[] = "abcdefgh";
    int a = 2, len = 4;
    char t[len + 1];
    strncpy(t, s + a, len);
    t[len] = '\0';
    // copy_substring(s, t, a, len);
    printf("%s\n", t);
    return 0;
}