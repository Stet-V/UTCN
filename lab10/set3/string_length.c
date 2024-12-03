#include <stdio.h>

int string_length(char *s) {
    if (*s == '\0')
        return 0;
    return 1 + string_length(s + 1);
}

int main() {
    char s[] = "abcdefgh";
    printf("%d\n", string_length(s));
    return 0;
}