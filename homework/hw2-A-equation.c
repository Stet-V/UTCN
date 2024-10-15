#include <stdio.h>

int main() {
    float a, b, c;
    char x;
    scanf("%f %c %f = %f", &a, &x, &b, &c);
    if (c)
        if ((x == '+' && a + b == c) || (x == '*' && a * b == c))
            printf("true\n");
         else printf("false\n");
    else printf("no operator\n");
    return 0;
}