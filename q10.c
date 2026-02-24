/* Q10: Maintain student records using Linked List
   (insert, delete, search, display) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct StudentNode {
    int rollNo;
    char studName[50];
    float marks;
    struct StudentNode* nextStud;
};
void insertStudent(struct StudentNode** headStud, int roll, char name[], float marks) {
    struct StudentNode* newStud = malloc(sizeof(struct StudentNode));
    newStud->rollNo = roll;
    strcpy(newStud->studName, name);
    newStud->marks = marks;
    newStud->nextStud = *headStud;
    *headStud = newStud;
}
void displayStudents(struct StudentNode* headStud) {
    while(headStud != NULL) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               headStud->rollNo, headStud->studName, headStud->marks);
        headStud = headStud->nextStud;
    }
}
struct StudentNode* searchStudent(struct StudentNode* headStud, int roll) {
    while(headStud != NULL) {
        if(headStud->rollNo == roll)
            return headStud;
        headStud = headStud->nextStud;
    }
    return NULL;
}
int main() {
    struct StudentNode* headStud = NULL;
    insertStudent(&headStud, 1, "Akshay", 85.5);
    insertStudent(&headStud, 2, "Ravi", 90.0);
    displayStudents(headStud);

    struct StudentNode* found = searchStudent(headStud, 1);
    if(found != NULL)
        printf("Student Found: %s\n", found->studName);
    return 0;
}
