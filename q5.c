/* Q5: Reverse data of nodes without changing links */
#include <stdio.h>
#include <stdlib.h>
struct RevNode {
    int dataVal;
    struct RevNode* nextAddr;
};
void reverseDataOnly(struct RevNode* headStart) {
    int size = 0, idx = 0;
    struct RevNode* travelPtr = headStart;

    while(travelPtr != NULL) {
        size++;
        travelPtr = travelPtr->nextAddr;
    }
    int tempArr[size];
    travelPtr = headStart;

    while(travelPtr != NULL) {
        tempArr[idx++] = travelPtr->dataVal;
        travelPtr = travelPtr->nextAddr;
    }
    travelPtr = headStart;
    idx = size - 1;
    while(travelPtr != NULL) {
        travelPtr->dataVal = tempArr[idx--];
        travelPtr = travelPtr->nextAddr;
    }
}
