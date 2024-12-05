#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007
typedef long long int ll;

ll highestPower(ll n, ll x) {
    ll p = 1;
    while (n % x == 0) {
        p *= x;
        n /= x;
    }
    return p;
}

void sieveEratosthenes(ll n, ll *primes, int *count) {
    int *isPrime = calloc(n + 1, sizeof(int));
    for (int i = 2; i <= n; i++)
        isPrime[i] = 1;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = 0;
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) {
            primes[*count] = i;
            (*count)++;
        }
    free(isPrime);
}

ll lcm(ll a, ll b) {
    ll lcm = 1, lim, size = sqrt(b); // sqrt(b) / log(sqrt(b)) Gauss-Legendre, Meissel–Lehmer
    ll *primes = malloc(size * sizeof(ll));
    int count = 0;
    sieveEratosthenes(size, primes, &count);
    ll *maxPower = calloc(b + 1, sizeof(ll));
    for (ll i = a; i <= b; i++) {
        lim = i;
        for (int j = 0; j < count && primes[j] * primes[j] <= lim; j++) {
            ll p = primes[j];
            if (lim % p == 0) {
                ll power = highestPower(lim, p);
                if (power > maxPower[p])
                    maxPower[p] = power;
                lim /= power;
            }
        }
        if (lim > 1)
            if (lim > maxPower[lim])
                maxPower[lim] = lim;
    }
    if ((b - a) > 5 || (b > 2000)) {
        for (ll i = 2; i <= lim; i++)
            if (maxPower[i] > 1)
                lcm = (lcm * maxPower[i]) % MOD;
        for (ll i = a; i <= b; i++)
            if (maxPower[i] > 1)
                lcm = (lcm * maxPower[i]) % MOD;
    } else {
        for (ll i = 2; i <= b; i++)
            if (maxPower[i] > 1)
                lcm = (lcm * maxPower[i]);
    }
    free(primes);
    free(maxPower);
    return lcm;
}

int main() {
    ll a, b;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", lcm(a, b));
    }
    return 0;
}