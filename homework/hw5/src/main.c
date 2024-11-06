#include <stdio.h>
#include "poe.h"

int main() {
    int H, W;
    scanf("%d %d", &H, &W);
    char a[H][W], rows[H];
    int cols[W];
    create_empty_map(H, W, a);
    print_map(H, W, a);
    char x;
    scanf(" %c", &x);
    int n = find_in_map(H, W, a, x, rows, cols);
    for (int i = 0; i < n; i++)
        printf("%c ", rows[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", cols[i]);
}