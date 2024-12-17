#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name;
    int octave;
    double duration;
} note;

int main() {
    FILE *pf = fopen("..\\input\\music_in.txt", "r");
    if (!pf)
        return -1;
    note *a = calloc(1e4, sizeof(note));
    int i = 0;
    while (fscanf(pf, "%c %d %lf\n", &a[i].name, &a[i].octave, &a[i].duration) == 3) {
        printf("%c%d %.2f\n", a[i].name, a[i].octave, a[i].duration);
        i++;
    }
    a = realloc(a, i * sizeof(note));
    free(a);
    fclose(pf);
    return 0;
}