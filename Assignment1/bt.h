#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "node.h"

typedef struct Node* BT;

void initBT(BT *t);
void insertBT(BT *t, int key);
void displayBT(BT t);
void displayBTPre(BT t);
void searchBT(BT t, int key, int * comparisonCount,int * gotDataFlag);
