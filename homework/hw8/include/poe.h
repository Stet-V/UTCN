#ifndef POE_H
#define POE_H

void create_empty_map(int H, int W, char a[H][W]);
char row_label(int i);
void print_map(int H, int W, char a[H][W]);
int find_in_map(int H, int W, char a[H][W], char x, char rows[], int cols[]);
void encode(int H, int W, char a[H][W], char* s);
void decode(int H, int W, char a[H][W], char* s);

#endif // POE_H