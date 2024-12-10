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

int compare(student a, student b) {
    int temp = strcmp(a.surname, b.surname);
    if (temp == 0)
        return strcmp(a.forename, b.forename);
    return temp;
}

int compareMark(student a, student b) {
    return a.mark < b.mark;
}

void sort(student *students, int n, int (*compare)(student, student)) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (compare(students[i], students[j]) > 0) {
                student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
}

int main() {
    int n;
    scanf("%d", &n);
    student *students = markbook(n);
    display(students, n);
    sort(students, n, compare);
    display(students, n);
    sort(students, n, compareMark);
    display(students, n);
    return 0;
}