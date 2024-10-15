// union of two intervals

#include <stdio.h>

int main () {
    float a, b, c, d, intersection;
    scanf("%f%f%f%f", &a, &b, &c, &d);
    if (a > b) {
        float temp = a;
        a = b;
        b = temp;
    }
    if (c > d) {
        float temp = c;
        c = d;
        d = temp;
    }
    if (b < c || d < a) {
        intersection = 0;
    } else {
        float start, end;
        if (a > c) start = a;
        else start = c;
        if (b < d) end = b;
        else end = d;
        intersection = end - start;
    }
    printf("%f\n", b - a + d - c - intersection);
    return 0;
}