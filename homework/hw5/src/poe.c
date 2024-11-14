#include <stdio.h>
#include "poe.h"

void create_empty_map(int H, int W, char a[H][W]) {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            a[i][j] = '.';
    a[0][0] = 'A';
    a[H-1][W-1] = 'B';
}

void print_map(int H, int W, char a[H][W]) {
    printf(" ");
    for (int i = 0; i < W; i++)
        printf("%d", i / 10);
    printf("\n ");
    for (int i = 0; i < W; i++)
        printf("%d", i % 10);
    printf("\n");
    for (int i = 0; i < H; i++) {
        printf("%c", (i < 26) ? ('A' + i) : ('a' + i - 26));
        for (int j = 0; j < W; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
}

int find_in_map(int H, int W, char a[H][W], char x, char rows[], int cols[]) {
    int k = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (a[i][j] == x) {
                rows[k] = i < 26 ? ('A' + i) : ('a' + i - 26);
                cols[k] = j + 1;
                k++;
            }
    return k;
}