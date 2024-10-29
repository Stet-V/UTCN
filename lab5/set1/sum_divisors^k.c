#include <stdio.h>
#include <math.h>

double sum(int n, int k) {
    double s = 1;
    s += pow(n, k);
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            s += pow(i, k);
            if (i != n / i)
                s += pow(n / i, k);
        }
    }
    return s;
}

int main() {
    long long int n;
    int k;
    scanf("%lld%d", &n, &k);
    printf("%f\n", sum(n, k));
    return 0;
}