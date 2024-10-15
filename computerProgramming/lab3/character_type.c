#include <stdio.h>

int main() {
    int c;
    scanf("%c", &c);
    if (c >= 'A' && c <= 'Z')
        printf("uppercase\n");
    else if (c >= 'a' && c <= 'z')
        printf("lowercase\n");
    else if (c >= '0' && c <= '9')
        printf("digit\n");
    else printf("other\n");
    return 0;
}