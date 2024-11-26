#include <stdio.h>
#include <string.h>

void insert_char(char *s, char c, int pos) {
    int n = strlen(s);
    for (int i = n; i >= pos; i--)
        s[i + 1] = s[i];
    s[pos] = c;
}

int main() {
    char s[10] = "abcdefghi";
    char c = 'z';
    int pos = 5;
    memmove(s + pos + 1, s + pos, strlen(s) - pos);
    s[pos] = c;
    // insert_char(s, c, pos);
    printf("%s\n", s);
    return 0;
}