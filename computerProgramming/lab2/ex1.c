// int %d
// float %f
// char  %c
// string %s 
// long long int %lld

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("a + b = %d\n", a + b);
    printf("a * b = %d\n", a * b);
    return 0;
}