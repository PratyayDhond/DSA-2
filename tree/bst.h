#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
	int data;
	struct Node *left, *right;
}Node;

typedef Node * BinarySearchTree ;

void initBst(BinarySearchTree *t);
void insert(BinarySearchTree *bst, int data);
int search(BinarySearchTree bst, int data);
void displayInorder(BinarySearchTree bst);
void displayPreorder(BinarySearchTree bst);
void displayPostorder(BinarySearchTree bst);

int isEmpty(BinarySearchTree bst);
int countLeaves(BinarySearchTree bst);
int countInternalNodes(BinarySearchTree bst);
