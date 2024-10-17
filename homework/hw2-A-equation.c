#include <stdio.h>

int main() {
    float a, b, c;
    char x;
    int r = scanf("%f %c %f = %f", &a, &x, &b, &c);
    if (r == 4)
        if ((x == '+' && a + b == c) || (x == '*' && a * b == c)) printf("true\n");
        else printf("false\n");
    else printf("invalid input\n");
    return 0;
}