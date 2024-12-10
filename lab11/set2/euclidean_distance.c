#include <stdio.h>
#include <math.h>

typedef struct {
    int x, y;
} point;

int distance(point p, point q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

int main() {
    point p, q;
    scanf("%d%d%d%d", &p.x, &p.y, &q.x, &q.y);
    printf("%d\n", distance(p, q));
    return 0;
}