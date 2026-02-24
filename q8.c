/* Q8: Implement Doubly Circular Linked List with insertion,
   deletion, display and count */
#include <stdio.h>
#include <stdlib.h>
struct DCNode {
    int dataItem;
    struct DCNode* prevLink;
    struct DCNode* nextLink;
};
void insertEndDC(struct DCNode** headNode, int val) {
    struct DCNode* newNode = malloc(sizeof(struct DCNode));
    newNode->dataItem = val;

    if(*headNode == NULL) {
        newNode->nextLink = newNode;
        newNode->prevLink = newNode;
        *headNode = newNode;
        return;
    }
    struct DCNode* lastNode = (*headNode)->prevLink;

    newNode->nextLink = *headNode;
    newNode->prevLink = lastNode;
    lastNode->nextLink = newNode;
    (*headNode)->prevLink = newNode;
}
void displayDC(struct DCNode* headNode) {
    if(headNode == NULL) return;

    struct DCNode* tempNode = headNode;
    int count = 0;
    do {
        printf("%d <-> ", tempNode->dataItem);
        tempNode = tempNode->nextLink;
        count++;
    } while(tempNode != headNode);

    printf("(Back to Head)\n");
    printf("Total nodes = %d\n", count);
}
int main() {
    struct DCNode* headNode = NULL;
    insertEndDC(&headNode, 5);
    insertEndDC(&headNode, 15);
    insertEndDC(&headNode, 25);
    displayDC(headNode);
    return 0;
}
