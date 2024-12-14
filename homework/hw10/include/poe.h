#ifndef POE_H
#define POE_H

void create_empty_map(int H, int W, char a[H][W]);
char row_label(int i);
void print_map(int H, int W, char a[H][W]);
int find_in_map(int H, int W, char a[H][W], char x, char rows[], int cols[]);
void encode(int H, int W, char a[H][W], char *s);
int row_label_index(char c);
void decode(int H, int W, char a[H][W], char *s);
typedef struct {
	short H, A, D, s, S;
} player;
typedef struct {
	short dH, dA, dD, dS;
} item;
typedef struct {
	char type;
	char torow;
	short tocol;
} move;
typedef struct {
	player players[2];
	char s[200];
} game_state;
int next_states(int H, int W, game_state *gs, char next_player, int n, item *items, game_state *ngs, move *moves);

#endif // POE_H