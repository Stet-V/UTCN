#include <stdio.h>

int lower_to_upper(char *s) {
    if (*s == '\0')
        return 0;
    if ((*s < 'a' || *s > 'z') && (*s < 'A' || *s > 'Z'))
        return -1;
    if (*s >= 'a' && *s <= 'z')
        *s = *s - 32;
    return lower_to_upper(s + 1);
}

int main() {
    char s[] = "aBcDeFg1H";
    lower_to_upper(s);
    printf("%d\n", lower_to_upper(s));
    if (!lower_to_upper(s))
        printf("%s\n", s);
    return 0;
}