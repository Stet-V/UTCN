// degrees -> radians

#include <stdio.h>
#include <math.h>

int main() {
    float x;
    double pi = acos(-1);
    scanf("%f", &x);
    printf("%.10frad\n", x * pi/180);
    return 0;
}