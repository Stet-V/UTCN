#include <stdio.h>
#include <string.h>

int last_position(char *s, char c) {
    int i = strlen(s) - 1;
    while (i >= 0) {
        if (s[i] == c) {
            return i;
        }
        i--;
    }
    return -1;
}

int main() {
    char s[]= "abcdefghc";
    char c = 'c';
    if (strrchr(s, c))
        printf("%d\n", strrchr(s, c) - s);
        else
            printf("-1\n");
    printf("%d\n", last_position(s, c));
    return 0;
}