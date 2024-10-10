// reading a string

#include <stdio.h>
#include <stdlib.h>

int main(){
    char s[100];
    scanf("%[^\n]", s);
//    gets(s);
    printf("%s\n", s);
    return 0;
}