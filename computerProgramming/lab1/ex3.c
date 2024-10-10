#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int p = 2;
    while(p * p <= n){
        while(n % p == 0){
            n /= p;
            printf("%d ", p);
        }
        p++;
    }
    if(n < 1)
        printf("%d ", n);
    return 0;
}
