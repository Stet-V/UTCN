#include <stdio.h>
#include <stdlib.h>

int literak(char *s, int k) {
    if (!*s)
        return 0;
    if ((s[0] == 'A' + (k - 1)) || (s[0] == 'a' + (k - 1)))
        return 1 + literak(s + 1, k);
    else return literak(s + 1, k);
}

int main() {
    printf("%d\n", literak("bbbb1", 2));
    return 0;
}