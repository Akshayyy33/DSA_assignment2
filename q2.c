/* Q2: Search an element in singly linked list and display position */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int dataItem;
    struct ListNode* nextNode;
};
int findPosition(struct ListNode* headRef, int searchKey) {
    int posIndex = 1;
    while(headRef != NULL) {
        if(headRef->dataItem == searchKey)
            return posIndex;
        headRef = headRef->nextNode;
        posIndex++;
    }
    return -1;
}
int main() {
    struct ListNode *headRef = NULL, *tempRef, *nodeRef;
    int totalNodes, dataVal, keyVal;
    printf("Enter number of nodes: ");
    scanf("%d", &totalNodes);

    for(int i = 0; i < totalNodes; i++) {
        nodeRef = (struct ListNode*)malloc(sizeof(struct ListNode));
        printf("Enter data: ");
        scanf("%d", &dataVal);

        nodeRef->dataItem = dataVal;
        nodeRef->nextNode = NULL;

        if(headRef == NULL)
            headRef = nodeRef;
        else {
            tempRef = headRef;
            while(tempRef->nextNode != NULL)
                tempRef = tempRef->nextNode;
            tempRef->nextNode = nodeRef;
        }
    }
    printf("Enter element to search: ");
    scanf("%d", &keyVal);
    int result = findPosition(headRef, keyVal);

    if(result == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", result);
    return 0;
}
