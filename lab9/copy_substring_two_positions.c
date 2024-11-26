#include <stdio.h>
#include <string.h>

void copy_substring(char *s, char *t, int a, int b) {
    int j = 0;
    for (int i = a; i < b; i++) {
        t[j] = s[i];
        j++;
    }
    t[j] = '\0';
}

int main() {
    char s[] = "abcdefgh";
    int a = 2, b = 5;
    char t[b - a + 1];
    strncpy(t, s + a, b - a);
    t[b - a] = '\0';
    // copy_substring(s, t, a, b);
    printf("%s\n", t);
    return 0;
}