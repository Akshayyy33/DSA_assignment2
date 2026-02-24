/* Q4: Delete node from beginning, end and after a given node */
#include <stdio.h>
#include <stdlib.h>
struct DelNode {
    int dataVal;
    struct DelNode* nextPtr;
};
void deleteBeginning(struct DelNode** headRef) {
    if(*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct DelNode* temp = *headRef;
    *headRef = temp->nextPtr;
    free(temp);
}
void deleteEnd(struct DelNode** headRef) {
    if(*headRef == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct DelNode *curr = *headRef, *prev = NULL;

    if(curr->nextPtr == NULL) {
        free(curr);
        *headRef = NULL;
        return;
    }

    while(curr->nextPtr != NULL) {
        prev = curr;
        curr = curr->nextPtr;
    }

    prev->nextPtr = NULL;
    free(curr);
}
void deleteAfter(struct DelNode* headRef, int keyVal) {
    while(headRef != NULL && headRef->dataVal != keyVal)
        headRef = headRef->nextPtr;

    if(headRef == NULL || headRef->nextPtr == NULL) {
        printf("Deletion not possible!\n");
        return;
    }

    struct DelNode* temp = headRef->nextPtr;
    headRef->nextPtr = temp->nextPtr;
    free(temp);
}
void insertEnd(struct DelNode** headRef, int val) {
    struct DelNode* newNode = malloc(sizeof(struct DelNode));
    newNode->dataVal = val;
    newNode->nextPtr = NULL;

    if(*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct DelNode* temp = *headRef;
    while(temp->nextPtr != NULL)
        temp = temp->nextPtr;

    temp->nextPtr = newNode;
}
void displayList(struct DelNode* headRef) {
    while(headRef != NULL) {
        printf("%d -> ", headRef->dataVal);
        headRef = headRef->nextPtr;
    }
    printf("NULL\n");
}
int main() {
    struct DelNode* headRef = NULL;
    int choice = 0, value, key;

    while(1) {
        printf("\n1.Insert End\n");
        printf("2.Delete Beginning\n");
        printf("3.Delete End\n");
        printf("4.Delete After\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter choice: ");

        if(scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting...\n");
            break;
        }

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&headRef, value);
                break;

            case 2:
                deleteBeginning(&headRef);
                break;

            case 3:
                deleteEnd(&headRef);
                break;

            case 4:
                if(headRef == NULL) {
                    printf("List is empty!\n");
                    break;
                }
                printf("Enter key value: ");
                scanf("%d", &key);
                deleteAfter(headRef, key);
                break;

            case 5:
                displayList(headRef);
                break;

            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
