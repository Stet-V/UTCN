#include <stdio.h>

int character_occurences(char *s, char c) {
    if (*s == '\0')
        return 0;
    return (*s == c) + character_occurences(s + 1, c);
}

int main() {
    char s[] = "cabcdefghc", c;
    scanf("%c", &c);
    printf("%d\n", character_occurences(s, c));
    return 0;
}