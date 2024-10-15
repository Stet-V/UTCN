#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, d, e, f;
    int start, end;
    scanf("[%f, %f] [%f, %f] [%f, %f]", &a, &b, &c, &d, &e, &f);
    if (a > c)
        if (a > e) start = ceil(a);
        else start = ceil(e);
    else if (c > e) start = ceil(c);
        else start = ceil(e);
    if (b < d)
        if (b < f) end = floor(b);
        else end = floor(f);
    else if (d < f) end = floor(d);
        else end = floor(f);
    if (start <= end) printf("%d\n", start);
    else printf("doesn't exist\n");
    return 0;
}