/* Q5: Reverse data of nodes without changing links */

#include <stdio.h>
#include <stdlib.h>

struct RevNode {
    int dataVal;
    struct RevNode* nextAddr;
};

void insertEnd(struct RevNode** headStart, int val) {
    struct RevNode* newNode = malloc(sizeof(struct RevNode));
    newNode->dataVal = val;
    newNode->nextAddr = NULL;

    if(*headStart == NULL) {
        *headStart = newNode;
        return;
    }

    struct RevNode* tempPtr = *headStart;
    while(tempPtr->nextAddr != NULL)
        tempPtr = tempPtr->nextAddr;

    tempPtr->nextAddr = newNode;
}

void displayList(struct RevNode* headStart) {
    while(headStart != NULL) {
        printf("%d -> ", headStart->dataVal);
        headStart = headStart->nextAddr;
    }
    printf("NULL\n");
}

void reverseDataOnly(struct RevNode* headStart) {
    int size = 0, index = 0;
    struct RevNode* travelPtr = headStart;

    while(travelPtr != NULL) {
        size++;
        travelPtr = travelPtr->nextAddr;
    }

    int tempArr[size];
    travelPtr = headStart;

    while(travelPtr != NULL) {
        tempArr[index++] = travelPtr->dataVal;
        travelPtr = travelPtr->nextAddr;
    }

    travelPtr = headStart;
    index = size - 1;

    while(travelPtr != NULL) {
        travelPtr->dataVal = tempArr[index--];
        travelPtr = travelPtr->nextAddr;
    }
}

int main() {
    struct RevNode* headStart = NULL;

    insertEnd(&headStart, 10);
    insertEnd(&headStart, 20);
    insertEnd(&headStart, 30);
    insertEnd(&headStart, 40);

    printf("Original List:\n");
    displayList(headStart);

    reverseDataOnly(headStart);

    printf("Reversed Data List:\n");
    displayList(headStart);

    return 0;
}
