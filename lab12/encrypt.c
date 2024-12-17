#include <stdio.h>
#include <stdlib.h>

void encrypt(char *a, int n, FILE *pf_out, int key) {
    for (int i = 0; i < n; i++) 
        fprintf(pf_out, "%c", a[i] ^ key);
}

int main () {
    FILE *pf_in = fopen("..\\input\\words_in.txt", "rb");
    if (!pf_in)
        return -1;
    fseek(pf_in, 0, SEEK_END);
    int n = ftell(pf_in);
    fseek(pf_in, 0, SEEK_SET);
    char *a = calloc(n + 1, sizeof(char));
    fread(a, sizeof(char), n, pf_in);
    FILE *pf_out = fopen("..\\output\\words_out.txt", "w");
    if (!pf_out)
        return -2;
    int key;
    scanf("%d", &key);
    encrypt(a, n, pf_out, key);
    free(a);
    fclose(pf_in);
    fclose(pf_out);
    return 0;
}