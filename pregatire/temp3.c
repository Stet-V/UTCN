#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char string[150];
    int isstea;
    char nume[50];
    char familie[50];
    float x, y, z;
    float a, b;
} planeta;

float distanta(planeta p1, planeta p2);



int main () {
    int n;


    FILE *pf = fopen("univers.txt", "r");
    if (!pf) 
        return -1;
    fscanf(pf, "%d\n", &n);
    planeta planete[n];
    for (int i = 0; i < n; i++) {
        fgets(planete[i].string, 150, pf);
        int k = 0;
        for (int j = 0; planete[i].string[j]; j++)
            if (planete[i].string[j] == '|')
                k++;
        if (k == 1) {
            planete[i].isstea = 1;
            sscanf(planete[i].string, " %[^|] | %f %f %f %f %f", planete[i].nume, &planete[i].x, &planete[i].y, &planete[i].z, &planete[i].a, &planete[i].b);
        }
        else {
            planete[i].isstea = 0;
            sscanf(planete[i].string, "%[^|] | %[^|] | %f %f %f", planete[i].nume, planete[i].familie, &planete[i].x, &planete[i].y, &planete[i].z);
        } 
    }
    for (int i = 0; i < n; i++) {
        if (planete[i].isstea) {
            for (int j = 0; j < n; j++) {
                if (!planete[j].isstea) {
                    float dist = distanta(planete[i], planete[j]);
                }
            }
        }

    }
}

float distanta (planeta p1, planeta p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
}