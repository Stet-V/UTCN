#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *pf_in = fopen("..\\input\\numbers_in.txt", "r");
    if (!pf_in) 
        return -1;
    int n;
    fscanf(pf_in, "%d", &n);
    double *a = calloc(n, sizeof(double));
    for (int i = 0; i < n; i++)
        fscanf(pf_in, "%lf", &a[i]);
    FILE *pf_out = fopen("..\\output\\numbers_out.txt", "w");
    if (!pf_out)
        return -2;
    fprintf(pf_out, "%d\n", n);
    for (int i = n - 1; i >= 0; i--)
        fprintf(pf_out, "%f ", a[i]);
    free(a);
    fclose(pf_in);
    fclose(pf_out);
    return 0;
}