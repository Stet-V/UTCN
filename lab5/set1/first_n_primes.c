#include <stdio.h>
#include <math.h>

int prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, k = 0, i = 2;
    scanf("%d", &n);
    while (k < n){
        if (prime(i)) {
            printf("%d\n", i);
            k++;
        }
        i++;
    }
    return 0;
}