/* Q6: Implement circular singly linked list with insertion and display */
#include <stdio.h>
#include <stdlib.h>

struct CircularNode {
    int dataField;
    struct CircularNode* nextField;
};
void insertEndCircular(struct CircularNode** headCirc, int newVal) {
    struct CircularNode* freshCirc = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    freshCirc->dataField = newVal;

    if(*headCirc == NULL) {
        *headCirc = freshCirc;
        freshCirc->nextField = *headCirc;
        return;
    }
    struct CircularNode* tempCirc = *headCirc;
    while(tempCirc->nextField != *headCirc)
        tempCirc = tempCirc->nextField;

    tempCirc->nextField = freshCirc;
    freshCirc->nextField = *headCirc;
}
void displayCircular(struct CircularNode* headCirc) {
    if(headCirc == NULL) return;

    struct CircularNode* moveCirc = headCirc;
    int nodeCounter = 0;

    do {
        printf("%d -> ", moveCirc->dataField);
        moveCirc = moveCirc->nextField;
        nodeCounter++;
    } while(moveCirc != headCirc);

    printf("(Back to Head)\n");
    printf("Total nodes = %d\n", nodeCounter);
}
int main() {
    struct CircularNode* headCirc = NULL;
    insertEndCircular(&headCirc, 11);
    insertEndCircular(&headCirc, 22);
    insertEndCircular(&headCirc, 33);

    displayCircular(headCirc);
    return 0;
}
