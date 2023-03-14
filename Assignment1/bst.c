#include "bst.h"

void initBst(BinarySearchTree *t){
	*t = NULL;
	return;
}

Node * createNewNodeBst(int key){
	Node* nn = (Node*) malloc(sizeof(Node));
	nn -> data = key;
	nn -> left = nn -> right = NULL;
	return nn;
}

Node * insertRecursivelyImplementation(Node *t, int key){
	if(!t)
		return createNewNodeBst(key);
	else if(t->data == key)
		return t ;//return NULL;
	else if(t->data > key)
		t->left = insertRecursivelyImplementation(t->left,key);
	else
		t->right = insertRecursivelyImplementation(t->right ,key);
	return t;
}

void insertRecursivelyBst(BinarySearchTree * t, int key){
	*t = insertRecursivelyImplementation(*t, key);
}

void insertBst(BinarySearchTree *bst, int data){
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

void getSearchCountBst(BinarySearchTree bst, int data, int * comparison){
//	printf("---------->        BST Search Count : %d\n",*comparison);
	if(!bst){
		*comparison += 1;
		return;
	}
	Node * p = bst;
	while(p){
		*comparison += 1;
		if(p->data == data)
			return;
		if(p->data > data)
			p = p -> left;
		else
			p = p -> right;
	}
	return;
}

int searchBst(BinarySearchTree bst, int data){
	
	if(bst == NULL)
		return 0;
	
	Node *p = bst;
	
	while(p){
	
		if(p->data == data)
			return 1;
		if(p->data > data)
			p = p -> left;
		//else if(p->data < data)
		else
			p = p -> right;
	}
	return 0;
}

void displayInorderBst(BinarySearchTree bst){
	if(!bst)
		return;

	displayInorderBst(bst->left);
	printf("%d ",bst->data);
	displayInorderBst(bst->right);
return;	
}

void displayPreorderBst(BinarySearchTree bst){
	if(!bst)
		return;
	
	printf("%d ", bst -> data );
	displayPreorderBst(bst->left);
	displayPreorderBst(bst->right);
return;
}

void displayPostorderBst(BinarySearchTree bst){
	if(!bst)
		return;

	displayPreorderBst(bst->left);
	displayPreorderBst(bst->right);
	printf("%d ", bst -> data );
return;	
}

int isEmptyBst(BinarySearchTree bst){
	if(!bst)
		return 1;
	else
		return 0;
}

int countLeavesBst(BinarySearchTree bst){
	if(!bst)
		return 0;
	if(!(bst->right) && !(bst->left)){
		return 1;	
	}
	return countLeavesBst(bst->left) + countLeavesBst(bst->right);
}

int countInternalNodesBst(BinarySearchTree bst){
	if(!bst)
		return 0;
	
	if(bst->right || bst -> left)
		return 1 + countInternalNodesBst(bst->right) + countInternalNodesBst(bst->left);
	else
		return 0;	
}


void printAncestorsBst(BinarySearchTree bst, int data){
	if(!bst)
		return;

	if(bst->data == data)
		return;
	else if(bst -> data < data)
		displayAncestorsBst(bst->right,data);
	else
		displayAncestorsBst(bst->left,data);
	printf("%d <-",bst->data);
return;
}

void displayAncestorsBst(BinarySearchTree bst, int data){

	if(!searchBst(bst,data)){
		return;
	}
	printAncestorsBst(bst,data);
	return;
}	
