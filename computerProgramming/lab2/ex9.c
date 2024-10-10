// reading a string

#include <stdio.h>

int main(){
    char s[100];
    scanf("%[^\n]", s);
//    gets(s);
    printf("%s\n", s);
    return 0;
}