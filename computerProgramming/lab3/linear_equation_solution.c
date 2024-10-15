// ax + b = 0

#include <stdio.h>

int main() {
    float a, b;
    scanf("%f%f", &a, &b);
    if (a == 0)
        if (b == 0)
            printf("any x\n");
        else
            printf("no solutions\n");
    else 
        printf("x = %f", -b/a);
    return 0;
}