#include <stdio.h>

int main() {
    int n;
    char c1, c2;
    scanf("%d %c %c", &n, &c1, &c2);
    if (c1 == 's' && c2 == 's')
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < i; j++)
                printf("#");
            printf("\n");
        }
    if (c1 == 's' && c2 == 'j')
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++)
                printf("#");
            printf("\n");
        }
    if (c1 == 'd' && c2 == 's')
        for (int i = n; i > 0; i--) {
            if (i != n)
                printf("%*c", n - i, ' ');
            for (int j = 0; j < i; j++)
                printf("#");
            printf("\n");
        }
    if (c1 == 'd' && c2 == 'j')
        for (int i = n; i > 0; i--) {
            if (i != 1)
                printf("%*c", i - 1, ' ');
            for (int j = 0; j < n - i + 1; j++)
                printf("#");
            printf("\n");
        }
    return 0;
}