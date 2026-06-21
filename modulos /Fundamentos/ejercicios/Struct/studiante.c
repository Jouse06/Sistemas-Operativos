#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    struct Student student;

    printf("Enter student name: ");
    scanf("%s", student.name);

    printf("Enter student age: ");
    scanf("%d", &student.age);

    printf("Enter student grade: ");
    scanf("%f", &student.grade);

    printf("\nStudent information:\n");
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Grade: %.2f\n", student.grade);

    return 0;
}
