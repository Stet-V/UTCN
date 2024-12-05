#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MOD 1000000007
typedef long long int ll;

ll gcd(ll x, ll y) {
    while (y != 0) {
        ll temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

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

ll segmentedSieve(ll a, ll b) {
    ll lcm = 1, sqrtb = sqrt(b), lim;
    ll *primes = malloc((sqrtb + 1) * sizeof(ll));
    int count = 0;
    sieveEratosthenes(sqrtb, primes, &count);
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
    for (ll i = 2; i <= lim; i++)
        if (maxPower[i] > 1)
            lcm = (lcm * maxPower[i]) % MOD;
    for (ll i = a; i <= b; i++)
        if (maxPower[i] > 1)
            lcm = (lcm * maxPower[i]) % MOD;
    free(primes);
    free(maxPower);
    return lcm;
}

int main() {
    clock_t begin = clock();
    ll a = 887654321;
    ll b = 887654325;
    printf("%lld\n", segmentedSieve(a, b));
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %f\n", time_spent);
    return 0;
}
