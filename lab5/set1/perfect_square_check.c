#include <stdio.h>

// #include <math.h>
// int perfect_square(long long int n) {
//     long long int r = sqrt(n);
//     return r * r == n;
// }

int perfect_square(long long int n) {
    long long int r = 0;
    while (r * r <= n) {
        if (r * r == n)
            return 1;
        r++;
    }
    return 0;
}

int main() {
    long long int n;
    scanf("%d", &n);
    printf("%d\n", perfect_square(n));
    return 0;
}