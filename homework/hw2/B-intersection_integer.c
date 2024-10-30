#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, d, e, f;
    int start, end;
    scanf("[%f, %f] [%f, %f] [%f, %f]", &a, &b, &c, &d, &e, &f);
    start = ceil(fmax(fmax(a, c), e));
    end = floor(fmin(fmin(b, d), f));
    if (start <= end) 
        printf("%d\n", start);
    else
        printf("doesn't exist\n");
    return 0;
}