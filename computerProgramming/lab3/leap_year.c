// leap year or not

#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
        printf("leap year\n");
    else
        printf("not a leap year\n");
}
