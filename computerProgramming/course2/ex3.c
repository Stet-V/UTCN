// C -> F

#include <stdio.h>
#include <stdlib.h>

int main(){
    float x;
    scanf("%f", &x);
    printf("%.2fF\n", x * 9/5 + 32);
    return 0;
}