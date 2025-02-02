#include <stdio.h>
#include <stdlib.h>

int consoane(char *s) {
    if (!*s)
        return 0;
    if (!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')))
        return -1;
    char ch = *s;
    if (ch >= 'A' && ch <= 'Z')
        ch += 32;
    char c[] = "bcdfghjklmnpqrstvwxyz";
    for (int i = 0; c[i]; i++)
        if (ch == c[i]) {
            int count = consoane(s + 1);
            return count == -1 ? -1 : count + 1;
        }
    return consoane(s + 1);
}

int main() {
    printf("%d\n", consoane("bb1"));
    return 0;
}