#include <stdio.h>
#include <stdlib.h>

int perforat(int x) {
    int cifre[10], n = 0;
    while (x) {
        cifre[n] = x % 10;
        x /= 10;
        n++;
    }
    int k = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (cifre[i] != cifre [n - 1] && cifre[i] != 0)
            return -1;
        if (cifre[i] == 0)
            k = 1;
    }
    if(k)
        return cifre[n - 1];
    return -1;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d %d\n", perforat(x), perforat(y));
    if((perforat(x) != perforat(y) && perforat(x) != -1))
        printf("imposibil\n");
        else  {
            int cifrex[10], cifrey[10], n = 0, m = 0;
            do {
                cifrex[n++] = x % 10;
                x /= 10;
            } while(x);
            do {
                cifrey[m++] = y % 10;
                y /= 10;
            } while(y);
            n--;
            m--;
            if (n < m) {
                printf("imposibil\n");
                return 0;
            }
            for (int i = 0; i < n && i < m; i++) {
                if ((cifrex[i] != cifrey[i]) && (cifrex[i] == 0)) {
                    printf("imposibil\n");
                    return 0;
                }
            }
            printf("posibil\n");
        }
    return 0;
}