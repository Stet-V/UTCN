#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char surname[25], forename[25];
    int age;
    char *address;
    float mark;
} student;

student *markbook(int n) {
    student *students = calloc(n, sizeof(student));
    int len = 10;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len; j++)
            students[i].surname[j] = 'a' + rand() % 26;
        students[i].surname[5 + rand() % 2] = '\0';
        for (int j = 0; j < len; j++)
            students[i].forename[j] = 'a' + rand() % 26;
        students[i].forename[len] = '\0';
        students[i].age = 18 + rand() % 2;
        students[i].address = calloc(2 * len + 1, sizeof(char));
        for (int j = 0; j < 2 * len; j++)
            students[i].address[j] = 'o' + rand() % 10;
        students[i].address[2 * len] = '\0';
        students[i].mark = 10.f / (1 + rand() % 3);
    }
    return students;
}

void display(student *students, int n) {
    for (int i = 0; i < n; i++)
        printf("%s %s %d %s %.2f\n", students[i].surname, students[i].forename, students[i].age, students[i].address, students[i].mark);
}

void removeStudent(student **students, int *n, char *studentremove) {
    for (int i = 0; i < *n; i++)
        if (strcmp((*students)[i].surname, studentremove) == 0) {
            (*n)--;
            for (int j = i; j < *n; j++)
                (*students)[j] = (*students)[j + 1];
        }
    *students = realloc(*students, *n * sizeof(student));
}

int main() {
    int n;
    scanf("%d", &n);
    student *students = markbook(n);
    display(students, n);
    char s[25];
    scanf("%s", s);
    removeStudent(&students, &n, s);
    display(students, n);
    return 0;
}