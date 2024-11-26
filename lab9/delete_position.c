#include <stdio.h>
#include <string.h>

void delete_position(char *s, int n) {
    if (n < strlen(s))
        for (int i = n; s[i] != '\0'; i++)
            s[i] = s[i + 1];
    s[strlen(s)] = '\0';
}
    
int main() {
    char s[] = "abcdefgh";
    int n = 5;
    // if (n < strlen(s))
    //     memmove(s + n, s + n + 1, strlen(s) - n);
    delete_position(s, n);
    printf("%s\n", s);
    return 0;
}