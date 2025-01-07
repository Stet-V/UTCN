#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Incorrect number of arguments\n");
        return -1;
    }
    printf("%s\n", argv[1]);
    char s[100];
    sprintf(s, "DIR %s /B > ../input/files.txt", argv[1]);
    system(s);
    FILE *pf = fopen("../input/files.txt", "r");
    if (!pf)
        return -2;
    char line[100];
    long long int sum = 0; 
    while (fgets(line, 100, pf)) {
        line[strlen(line) - 1] = '\0';
        char filename[200];
        sprintf(filename, "%s\\%s", argv[1], line);
        FILE *pf2 = fopen(filename, "r");
        if (pf2) {
            fseek(pf2, 0, SEEK_END);
            sum += ftell(pf2);
            fclose(pf2);
        }
    }
    printf("%lld\n", sum);
    fclose(pf);
    return 0;
}