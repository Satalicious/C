
/*
https://bulme.find-santa.eu/exercises/c/exercise_structs/
2. Student Data
Implement a struct that stores information about a student in a new type called Student. 
Each student has a char first_name[30], char last_name[50] and a unsigned long id. 
Implement the following functions:
            Student read_student();  // read student information from stdin
            // print one student per line to stdout
            void print_students(Student students[], size_t dimension);
In main(.) ask the user how many students should be stored. 
Create an array holding the correct number of students and 
fill the array by repeatedly calling read_student(). 
Once finished, print your in-memory student database to stdout.
*/

#include <stdio.h>
#include <iostream>

typedef struct {
    char first_name[30], 
    char last_name[50], 
    unsigned long id
} Student;

Student read_student() {
    printf("Enter first name of the student: ");
    students.first_name = getchar();
}
void print_students(Student students[], size_t dimension);

int main() {
    printf("How many students should be stored in the database?\n");
    int numstudents = getchar();
    Student students[numstudents] = {};
    for (int i = 0; i < numstudents; i++)
        read_student();  // read student information from stdin
    
    return 0;
}