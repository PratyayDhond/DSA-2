#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *left, *right;
}Node;

typedef Node * BinarySearchTree ;

void initBst(BinarySearchTree *t);
void insert(BinarySearchTree *bst, int data);
int search(BinarySearchTree bst, int data);

