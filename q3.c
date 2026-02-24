/* Q3: Perform insertion at beginning, end and after a given node */
#include <stdio.h>
#include <stdlib.h>

struct InsNode {
    int dataVal;
    struct InsNode* nextPtr;
};
void insertBeginning(struct InsNode** headRef, int val) {
    struct InsNode* newNode = malloc(sizeof(struct InsNode));
    newNode->dataVal = val;
    newNode->nextPtr = *headRef;
    *headRef = newNode;
}
void insertEnd(struct InsNode** headRef, int val) {
    struct InsNode* newNode = malloc(sizeof(struct InsNode));
    newNode->dataVal = val;
    newNode->nextPtr = NULL;

    if(*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct InsNode* walk = *headRef;
    while(walk->nextPtr != NULL)
        walk = walk->nextPtr;

    walk->nextPtr = newNode;
}
void insertAfter(struct InsNode* headRef, int keyVal, int newVal) {
    while(headRef != NULL && headRef->dataVal != keyVal)
        headRef = headRef->nextPtr;

    if(headRef == NULL) {
        printf("Key not found!\n");
        return;
    }
    struct InsNode* newNode = malloc(sizeof(struct InsNode));
    newNode->dataVal = newVal;
    newNode->nextPtr = headRef->nextPtr;
    headRef->nextPtr = newNode;
}
void displayList(struct InsNode* headRef) {
    while(headRef != NULL) {
        printf("%d -> ", headRef->dataVal);
        headRef = headRef->nextPtr;
    }
    printf("NULL\n");
}
int main() {
    struct InsNode* headRef = NULL;
    int choice, value, key;
    do {
        printf("\n1.Insert Beginning\n2.Insert End\n3.Insert After\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(&headRef, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&headRef, value);
                break;

            case 3:
                printf("Enter key value: ");
                scanf("%d", &key);
                printf("Enter new value: ");
                scanf("%d", &value);
                insertAfter(headRef, key, value);
                break;

            case 4:
                displayList(headRef);
                break;
        }
    } while(choice != 5);
    return 0;
}
