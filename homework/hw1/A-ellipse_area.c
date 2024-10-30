#include <stdio.h>
#include <math.h>

int main() {
    double a, b, area, pi = acos(-1);
    scanf("%lf%lf", &a, &b);
    area = pi * a * b;
    printf("%.2lf\n", area);
    return 0;
}