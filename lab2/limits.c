#include <stdio.h>
#include <limits.h>

int main() {
    printf("int [%d, %d]\n", INT_MIN, INT_MAX);
    printf("char [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned int [0, %u]\n", UINT_MAX);
    printf("short int [%hd, %hd]\n", SHRT_MIN, SHRT_MAX);
    printf("long long int [%lld, %lld]\n", LLONG_MIN, LLONG_MAX);

    printf("%d\n", __SCHAR_WIDTH__);
    printf("%d\n", CHAR_BIT);
    return 0;
}