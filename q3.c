/* Q3: Perform insertion at beginning, end and after a given node */
#include <stdio.h>
#include <stdlib.h>
struct NodeRec {
    int info;
    struct NodeRec* nextLink;
};
void insertFront(struct NodeRec** startNode, int newVal) {
    struct NodeRec* freshNode = (struct NodeRec*)malloc(sizeof(struct NodeRec));
    freshNode->info = newVal;
    freshNode->nextLink = *startNode;
    *startNode = freshNode;
}
void insertRear(struct NodeRec** startNode, int newVal) {
    struct NodeRec* freshNode = (struct NodeRec*)malloc(sizeof(struct NodeRec));
    freshNode->info = newVal;
    freshNode->nextLink = NULL;

    if(*startNode == NULL) {
        *startNode = freshNode;
        return;
    }
    struct NodeRec* walkNode = *startNode;
    while(walkNode->nextLink != NULL)
        walkNode = walkNode->nextLink;
    walkNode->nextLink = freshNode;
}
void insertAfterKey(struct NodeRec* startNode, int keyVal, int newVal) {
    while(startNode != NULL && startNode->info != keyVal)
        startNode = startNode->nextLink;

    if(startNode != NULL) {
        struct NodeRec* freshNode = (struct NodeRec*)malloc(sizeof(struct NodeRec));
        freshNode->info = newVal;
        freshNode->nextLink = startNode->nextLink;
        startNode->nextLink = freshNode;
    }
    else
        printf("Key not found\n");
}
void showList(struct NodeRec* startNode) {
    while(startNode != NULL) {
        printf("%d -> ", startNode->info);
        startNode = startNode->nextLink;
    }
    printf("NULL\n");
}
int main() {
    struct NodeRec* startNode = NULL;
    insertFront(&startNode, 5);
    insertRear(&startNode, 20);
    insertAfterKey(startNode, 5, 10);
    showList(startNode);
    return 0;
}
