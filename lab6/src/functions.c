#include <stdio.h>
#include "functions.h"

void read(int n, float a[]) {
    for(int i = 0; i < n; i++){
        scanf("%f", &a[i]);
    }
}

void print(int n, float a[]) {
    for(int i = 0; i < n; i++){
        printf("%f ", a[i]);
    }
    printf("\n");
}

float minval(int n, float a[]) {
    float min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int min(int n, float a[]) {
    int min = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[min]) {
            min = i;
        }
    }
    return min + 1;
}

float sum(int n, float a[]) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

void inverse(int n, float a[]) {
    for (int i = 0; i < n / 2; i++) {
        float temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

void bubble(int n, float a[]) {
    int x = 1;
    while (x){
        x = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]){
                float temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                x = 1;
            }
        }
    }
}