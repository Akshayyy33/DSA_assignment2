/* Q9: Represent and evaluate polynomial using Linked List */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct PolyNode {
    int coeff;
    int power;
    struct PolyNode* nextTerm;
};
void insertTerm(struct PolyNode** polyHead, int c, int p) {
    struct PolyNode* newTerm = malloc(sizeof(struct PolyNode));
    newTerm->coeff = c;
    newTerm->power = p;
    newTerm->nextTerm = *polyHead;
    *polyHead = newTerm;
}
double evaluatePoly(struct PolyNode* polyHead, int xVal) {
    double result = 0;
    while(polyHead != NULL) {
        result += polyHead->coeff * pow(xVal, polyHead->power);
        polyHead = polyHead->nextTerm;
    }
    return result;
}
int main() {
    struct PolyNode* polyHead = NULL;
    insertTerm(&polyHead, 3, 2);  
    insertTerm(&polyHead, 2, 1);  
    insertTerm(&polyHead, 1, 0); 

    int xVal = 2;
    printf("Polynomial value at x=%d is %.2lf\n", xVal, evaluatePoly(polyHead, xVal));
    return 0;
}
