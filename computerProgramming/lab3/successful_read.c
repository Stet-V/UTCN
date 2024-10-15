#include <stdio.h>

int main() {
    int x;
    int r = scanf("%d", &x);
    if (r == 1)
        printf("Input read successfully: %d\n", x);
    else 
        printf("Failed to read input.\n");
    return 0;
}