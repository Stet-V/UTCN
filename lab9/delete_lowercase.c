#include <stdio.h>
#include <string.h>

void delete_lowercase(char *s) {
    int k = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[k] = s[i];
            k++;
        }
    s[k] = '\0';
}

int main() {
    char s[] = "abAdDeFDghc";
    // for (int i = 0; s[i] != '\0'; i++) {
    //     if (islower(s[i])) {
    //         memmove(s + i, s + i + 1, strlen(s + i));
    //         i--;
    //     }
    // }
    delete_lowercase(s);  
    printf("%s\n", s);
    return 0;
}