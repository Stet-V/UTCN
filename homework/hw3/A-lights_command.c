#include <stdio.h>

int main() {
    int n, k;
    unsigned int lights = 0;
    char command;
    scanf("%d", &n);
    while (1) {
        printf("command: ");
        scanf(" %c", &command);
        switch (command) {
            case 's':
                lights = 0;
                break;
            case 'a':
                lights = (1U << n) - 1;
                break;
            case '0':
                printf("k: ");
                scanf("%d", &k);
                lights &= ~(1U << k);
                break;
            case '1':
                printf("k: ");
                scanf("%d", &k);
                lights |= (1U << k);
                break;
            case 't':
                printf("k: ");
                scanf("%d", &k);
                lights ^= (1U << k);
                break;
            case 'x':
                return 0;
        }
        printf("%u\n", lights);
    }
    return 0;
}