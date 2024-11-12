#include <stdio.h>

void copy(char *a, char *b, int n) {
    for (int i = 0; i < n; i++)
        *(b + i) = *(a + i);
}

int main () {
    int n;
    scanf("%d", &n);
    char a[n], b[n];
    for (int i = 0; i < n; i++)
        scanf(" %c", &a[i]);
    copy(a, b, n);
    for (int i = 0; i < n; i++)
        printf("%c ", b[i]);
    printf("\n");
    return 0;
}