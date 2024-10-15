// fractional part

#include <stdio.h>
#include <math.h>

int main() {
    float x;
    scanf("%f", &x);
    int y = floor(x);
    printf("%f\n", fabs(x - y));
    return 0;
}