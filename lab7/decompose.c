#include <stdio.h>
#include <math.h>

void decompose(double x, int *integer, double *frac) {
    *integer = (int)x;
    if (x < 0 && *frac != 0) {
        *integer -= 1;
        *frac = x - *integer;
    }
    *frac = x - *integer;
}

int main() {
    double x;
    scanf("%lf", &x);
    int integer;
    double frac;
    decompose(x, &integer, &frac);
    printf("%d %f\n", abs(integer), fabs(frac));
    return 0;
}