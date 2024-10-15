// digits of a 4-digit number displayed in reverse order without the use of a loop

#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    printf("%d%d%d%d\n", x % 10, x / 10 % 10, x / 100 % 10, x / 1000);
    return 0;
}