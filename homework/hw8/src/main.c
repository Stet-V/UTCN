#include <stdio.h>
#include <stdlib.h>
#include "poe.h"

int main() {
    // int H = 3, W = 5;
    // char a[3][5] = {
    //     {'.', '.', '.', 'm', '.'},
    //     {'.', 'A', '.', '.', '1'},
    //     {'.', 'B', '.', '0', '.'}
    // };
    // print_map(H, W, a);
    // char *s = calloc(150, sizeof(char));
    // encode(H, W, a, s);
    // printf("%s\n", s);
    int H = 3, W = 5;
    char a[3][5] = {
        {'.', 'm', '.', 'm', '.'},
        {'.', '.', 'A', '.', '0'},
        {'B', '.', '1', '2', '3'}
    };
    print_map(H, W, a);
    char s[] = "m A4 A B2 o1 B5 B C2 o0 C4";
    decode(H, W, a, s);
    print_map(H, W, a);
    return 0;
}