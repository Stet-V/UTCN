#include <stdio.h>
#include <string.h>
#include "poe.h"

int main() {
    int H = 4, W = 5;
    char a[H][W];
    create_empty_map(H, W, a);
    player p1 = {100, 40, 0, 20, 20};
    item o1 = {.dH  = 10};
    item o2 = {.dA = -5};
    item items[] = {o1, o2};
    int n = 2;
    game_state gs = {
	    {p1, p1},
    };
    strcpy(gs.s, "A A3 o1 B1 B C1 o2 C5");
    decode(H, W, a, gs.s);
    print_map(H, W, a);
    printf("H: %d, A: %d, D: %d, s: %d S: %d\n", gs.players[0].H, gs.players[0].A, gs.players[0].D, gs.players[0].s, gs.players[0].S);
    game_state ngs[10];
    move moves[10];
    int states = next_states(H, W, &gs, 'A', n, items, ngs, moves);
    for (int i = 0; i < states; i++){
        decode(H, W, a, ngs[i].s);
        print_map(H, W, a);
        printf("%c %c%d\n", moves[i].type, moves[i].torow, moves[i].tocol);
        printf("H: %d, A: %d, D: %d, s: %d S: %d\n", ngs[i].players[0].H, ngs[i].players[0].A, ngs[i].players[0].D, ngs[i].players[0].s, ngs[i].players[0].S);
    }
    return 0;
}