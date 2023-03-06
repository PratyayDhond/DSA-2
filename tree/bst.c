#include "bst.h"

void initBst(BinarySearchTree *t){
	*t = NULL;
	return;
}

void insert(BinarySearchTree *bst, int data){
	Node *nn = (Node *) malloc(sizeof(Node));
	if(!nn)
		return;
	nn -> data = data;
	nn -> left = nn -> right = NULL;
	
	if(*bst == NULL){
		*bst = nn;
		return;
	}
	
	Node * p = *bst;
	Node * q = NULL;
	
	while(p){
	 	q = p;
		if(p -> data == data)
			return;
		if(p-> data > data)
			p = p -> left;
		else
			p = p -> right;
	}
	
	if(q->data > data)
		q->left = nn;
	else
		q->right = nn;
	
	return;		
}

int search(BinarySearchTree bst, int data){
	
	if(bst == NULL)
		return 0;
	
	Node *p = bst;
	
	while(p){
		if(p->data == data)
			return 1;
		if(p->data > data)
			p = p -> left;
		if(p->data < data)
			p = p -> right;
	}
	return 0;
}
