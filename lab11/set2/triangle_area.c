#include <stdio.h>

typedef struct {
    int x, y;
} point;

int triange_area(point a, point b, point c) {
    return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

int main() {
    point a, b, c;
    scanf("%d%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
    printf("%d\n", triange_area(a, b, c));
    return 0;
}