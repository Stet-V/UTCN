#include <stdio.h>
#include <string.h>

int strlen0(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int main () {
    char s[] = "abcdefgh";
    printf("%d\n", strlen(s));
    printf("%d\n", strlen0(s));
    return 0;
}