#include <stdio.h>
#include <stdlib.h>

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

student *markBelow5(student *students, int n, int *k) {
    *k = 0;
    for (int i = 0; i < n; i++)
        if (students[i].mark < 5)
            (*k)++;
    student *studentsBelow5 = calloc(*k, sizeof(student));
    *k = 0;
    for (int i = 0; i < n; i++)
        if (students[i].mark < 5) {
            studentsBelow5[*k] = students[i];
            (*k)++;
        }
    return studentsBelow5;
}

int main() {
    int n;
    scanf("%d", &n);
    student *students = markbook(n);
    display(students, n);
    int k;
    student *studentsBelow5 = markBelow5(students, n, &k);
    display(studentsBelow5, k);
    return 0;
}