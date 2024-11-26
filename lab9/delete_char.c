#include <stdio.h>
#include <string.h>

void delete_char(char *s, char c) {
    int k = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] != c) {
            s[k] = s[i];
            k++;
        }
    s[k] = '\0';
}

int main() {
    char s[] = "abcdcefcghc";
    char c = 'c';
    // while(strchr(s, c))
    //     memmove(strchr(s, c), strchr(s, c) + 1, strlen(strchr(s, c)));
    delete_char(s, c);
    printf("%s\n", s);
    return 0;
}