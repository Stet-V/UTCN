// first decimal

#include <stdio.h>
#include <math.h>

int main(){
    float x;
    scanf("%f", &x);
    printf("%d\n", abs((int)(x * 10) % 10));
    return 0;
}