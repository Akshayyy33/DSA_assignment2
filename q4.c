/* Q4: Delete node from beginning, end and after a given node */

#include <stdio.h>
#include <stdlib.h>

struct DelNode {
    int element;
    struct DelNode* nextPtr;
};
void deleteFront(struct DelNode** headNode) {
    if(*headNode == NULL) return;

    struct DelNode* tempNode = *headNode;
    *headNode = tempNode->nextPtr;
    free(tempNode);
}
void deleteRear(struct DelNode** headNode) {
    if(*headNode == NULL) return;

    struct DelNode *currNode = *headNode, *prevNode = NULL;

    if(currNode->nextPtr == NULL) {
        free(currNode);
        *headNode = NULL;
        return;
    }
    while(currNode->nextPtr != NULL) {
        prevNode = currNode;
        currNode = currNode->nextPtr;
    }
    prevNode->nextPtr = NULL;
    free(currNode);
}
void deleteAfterKey(struct DelNode* headNode, int keyVal) {
    while(headNode != NULL && headNode->element != keyVal)
        headNode = headNode->nextPtr;
    if(headNode != NULL && headNode->nextPtr != NULL) {
        struct DelNode* tempNode = headNode->nextPtr;
        headNode->nextPtr = tempNode->nextPtr;
        free(tempNode);
    }
}
int main() {
    return 0;
}
