#include <stdio.h>

void seconds_to_hms(long long int seconds, int *h, int *m, int *s) {
    *h = seconds / 3600;
    *m = (seconds % 3600) / 60;
    *s = seconds % 60;
}

int main() {
    long long int seconds;
    int h, m, s;
    scanf("%lld", &seconds);
    seconds_to_hms(seconds, &h, &m, &s);
    printf("%lld %lld %lld\n", h, m, s);
    return 0;
}