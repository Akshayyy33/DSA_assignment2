/* Q7: Implement Doubly Linked List with creation, insertion,
   deletion, forward & backward traversal, and counting */
#include <stdio.h>
#include <stdlib.h>
struct DNode {
    int dataVal;
    struct DNode* prevPtr;
    struct DNode* nextPtr;
};
void insertFront(struct DNode** headRef, int val) {
    struct DNode* newNode = malloc(sizeof(struct DNode));
    newNode->dataVal = val;
    newNode->prevPtr = NULL;
    newNode->nextPtr = *headRef;

    if(*headRef != NULL)
        (*headRef)->prevPtr = newNode;

    *headRef = newNode;
}
void insertEnd(struct DNode** headRef, int val) {
    struct DNode* newNode = malloc(sizeof(struct DNode));
    newNode->dataVal = val;
    newNode->nextPtr = NULL;
    if(*headRef == NULL) {
        newNode->prevPtr = NULL;
        *headRef = newNode;
        return;
    }
    struct DNode* walk = *headRef;
    while(walk->nextPtr != NULL)
        walk = walk->nextPtr;

    walk->nextPtr = newNode;
    newNode->prevPtr = walk;
}
void deleteFront(struct DNode** headRef) {
    if(*headRef == NULL) return;

    struct DNode* temp = *headRef;
    *headRef = temp->nextPtr;

    if(*headRef != NULL)
        (*headRef)->prevPtr = NULL;
    free(temp);
}
void displayForward(struct DNode* headRef) {
    while(headRef != NULL) {
        printf("%d <-> ", headRef->dataVal);
        headRef = headRef->nextPtr;
    }
    printf("NULL\n");
}                      
int countNodes(struct DNode* headRef) {
    int counter = 0;
    while(headRef != NULL) {
        counter++;
        headRef = headRef->nextPtr;
    }
    return counter;
}
int main() {
    struct DNode* headRef = NULL;
    insertFront(&headRef, 10);
    insertEnd(&headRef, 20);
    insertEnd(&headRef, 30);

    displayForward(headRef);
    printf("Total nodes = %d\n", countNodes(headRef));
    return 0;
}
