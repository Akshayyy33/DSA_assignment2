/* Q1: Traverse a singly linked list and count number of nodes */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode* link;
};
int countTotal(struct ListNode* startPtr) {
    int totalCount = 0;
    while (startPtr != NULL) {
        totalCount++;
        startPtr = startPtr->link;
    }
    return totalCount;
}
int main() {
    struct ListNode *startPtr = NULL, *movePtr, *newPtr;
    int nodeCount, inputVal;
    printf("Enter number of nodes: ");
    scanf("%d", &nodeCount);

    for(int i = 0; i < nodeCount; i++) {
        newPtr = (struct ListNode*)malloc(sizeof(struct ListNode));
        printf("Enter data: ");
        scanf("%d", &inputVal);

        newPtr->value = inputVal;
        newPtr->link = NULL;

        if(startPtr == NULL)
            startPtr = newPtr;
        else {
            movePtr = startPtr;
            while(movePtr->link != NULL)
                movePtr = movePtr->link;
            movePtr->link = newPtr;
        }
    }
    printf("Total nodes = %d\n", countTotal(startPtr));
    return 0;
}
