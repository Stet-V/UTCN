#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char first[100], last[100];
    int x, v;
    scanf("%[^\n]", name);
    scanf("%d%d", &x, &v);
    sscanf(name, "%s %s", first, last);
    printf("%s%03d\\%X\n", last, x, v);
    return 0;
}