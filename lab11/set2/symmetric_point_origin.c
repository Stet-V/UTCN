#include <stdio.h>

typedef struct {
    int x, y;
} point;

point symmetric_point(point p) {
    p.x = -p.x;
    p.y = -p.y;
    return p;
}

int main() {
    point p;
    scanf("%d%d", &p.x, &p.y);
    point q = symmetric_point(p);
    printf("%d %d\n", q.x, q.y);
}