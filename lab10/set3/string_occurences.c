#include <stdio.h>

int string_occurences(char *s, char c1, char c2) {
    if (*s == '\0' || *(s + 1) == '\0')
        return 0;
    return (*s == c1 && *(s+1) == c2) + string_occurences(s + 1, c1, c2);
}

int main() {
    char s[] = "abcdefabghiab", c1, c2;
    scanf("%c %c", &c1, &c2);
    printf("%d\n", string_occurences(s, c1, c2));
    return 0;
}