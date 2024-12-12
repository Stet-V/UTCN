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
    ll lcm = 1, size = (b - a > sqrt(b)) ? (b - a) : (ll)sqrt(b);
    ll *primes = malloc(size * sizeof(ll));
    int count = 0;
    sieveEratosthenes(size, primes, &count);
    ll *maxPower = calloc(count, sizeof(ll));
    for (int j = 0; j < count; j++) {
        ll p = primes[j];
        ll maxP = 0;
        for (ll i = a; i <= b; i++) {
            ll power = highestPower(i, p);
            if (power > maxP)
                maxP = power;
        }
        maxPower[j] = maxP;
    }
    int useMod = (b - a > 5 || b > 2000);
    for (int j = 0; j < count; j++)
        if (maxPower[j] > 1)
            lcm = useMod ? (lcm * maxPower[j]) % MOD : lcm * maxPower[j];
    for (ll i = a; i <= b; i++) {
        ll temp = i;
        for (int j = 0; j < count; j++)
            while (temp % primes[j] == 0)
                temp /= primes[j];
        if (temp > 1)
            lcm = useMod ? (lcm * temp) % MOD : lcm * temp;
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