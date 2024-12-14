#include <stdio.h>
#include <string.h>
#include "poe.h"

void create_empty_map(int H, int W, char a[H][W]) {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            a[i][j] = '.';
    a[0][0] = 'A';
    a[H-1][W-1] = 'B';
}

char row_label(int i) {
    return i < 26 ? ('A' + i) : ('a' + i - 26);
}

void print_map(int H, int W, char a[H][W]) {
    printf(" ");
    for (int i = 1; i <= W; i++)
        printf("%d", i / 10);
    printf("\n ");
    for (int i = 1; i <= W; i++)
        printf("%d", i % 10);
    printf("\n");
    for (int i = 0; i < H; i++) {
        printf("%c", row_label(i));
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
                rows[k] = row_label(i);
                cols[k] = j + 1;
                k++;
            }
    return k;
}

void encode(int H, int W, char a[H][W], char *s) {
    int k = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (a[i][j] != '.') {
                if (a[i][j] >= '0' && a[i][j] <= '9')
                    k += sprintf(s + k, "o");
                k += sprintf(s + k, "%c %c%d ", a[i][j], row_label(i), j + 1);
            }
    s[k - 1] = '\0';
}

int row_label_index(char c) {
    return c >= 'a' ? (c - 'a' + 26) : (c - 'A');
}

void decode(int H, int W, char a[H][W], char *s) {
    char c, row, prefix;
    int column;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            a[i][j] = '.';
    while (*s) {
        int n = 0;
        sscanf(s, "%c%c %c%d %n", &prefix, &c, &row, &column, &n);
        if (prefix != 'o')
            c = prefix;
        a[row_label_index(row)][column - 1] = c;
        s += n;
    }
}

int next_states(int H, int W, game_state *gs, char next_player, int n, item *items, game_state *ngs, move *moves) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        game_state new_state = *gs;
        char item_label[5];
        sprintf(item_label, "o%d ", i + 1);
        char* item_pos = strstr(new_state.s, item_label);
        if (item_pos) {
            move new_move;
            new_move.type = 'm';
            sscanf(item_pos + 3, "%c%d", &new_move.torow, &new_move.tocol);
            strcpy(item_pos, item_pos + 1);
            *item_pos = next_player;
            char *pos = strchr(new_state.s, next_player);
            strcpy(pos, pos + 5);
            new_state.players[next_player - 'A'].H += items[i].dH;
            new_state.players[next_player - 'A'].A += items[i].dA;
            new_state.players[next_player - 'A'].D += items[i].dD;
            new_state.players[next_player - 'A'].S += items[i].dS;
            ngs[k] = new_state;
            moves[k] = new_move;
            k++;
        }
    }
    return k;
}