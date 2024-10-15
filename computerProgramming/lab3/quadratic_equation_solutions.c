// ax^2 + bx + c = 0

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    if(a == 0)
        if (b == 0)
            if (c == 0)
                printf("any x\n");
            else
                printf("no solutions\n");
        else 
        printf("x = %f", -c / b);
    else{
        float discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            float x1 = (-b + sqrt(discriminant)) / (2 * a);
            float x2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("x1 = %f, x2 = %f\n", x1, x2);
        } else if (discriminant == 0) {
            float x = -b / (2 * a);
            printf("x = %f\n", x);
        } else {
            float xr = -b / (2 * a);
            float xi = sqrt(-discriminant) / (2 * a);
            printf("x1 = %f + %fi, x2 = %f - %fi\n", xr, xi, xr, xi);
        }
    }
    return 0;
}