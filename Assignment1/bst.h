#include<stdlib.h>
#include<stdio.h>
#include "node.h"

typedef Node * BinarySearchTree ;

void initBst(BinarySearchTree *t);
void insertBst(BinarySearchTree *bst, int data);
int searchBst(BinarySearchTree bst, int data);
void displayInorderBst(BinarySearchTree bst);
void displayPreorderBst(BinarySearchTree bst);
void displayPostorderBst(BinarySearchTree bst);

int isEmptyBst(BinarySearchTree bst);
int countLeavesBst(BinarySearchTree bst);
int countInternalNodesBst(BinarySearchTree bst);
void displayAncestorsBst(BinarySearchTree bst, int key);
void insertRecursivelyBst(BinarySearchTree *t, int key);
void getSearchCountBst(BinarySearchTree bst, int data, int * comparison);
