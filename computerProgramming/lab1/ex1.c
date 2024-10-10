#include <stdio.h>
#include <stdlib.h>

int main(){
    float x;
    scanf("%f", &x);
    long long s = 0, i = 1;
    while(i <= x){
        s += i;
        i += 2;
    }
    printf("%lld\n", s);
    return 0;
}
