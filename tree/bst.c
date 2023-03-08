#include "bst.h"

void initBst(BinarySearchTree *t){
	*t = NULL;
	return;
}

Node * createNewNode(int key){
	Node* nn = (Node*) malloc(sizeof(Node));
	nn -> data = key;
	nn -> left = nn -> right = NULL;
	return nn;
}

Node * insertRecursivelyImplementation(Node *t, int key){
	if(!t)
		return createNewNode(key);
	else if(t->data == key)
		return t ;//return NULL;
	else if(t->data > key)
		t->left = insertRecursivelyImplementation(t->left,key);
	else
		t->right = insertRecursivelyImplementation(t->right ,key);
	return t;
}

void insertRecursively(BinarySearchTree * t, int key){
	*t = insertRecursivelyImplementation(*t, key);
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
		//else if(p->data < data)
		else
			p = p -> right;
	}
	return 0;
}

void displayInorder(BinarySearchTree bst){
	if(!bst)
		return;

	displayInorder(bst->left);
	printf("%d ",bst->data);
	displayInorder(bst->right);
return;	
}

void displayPreorder(BinarySearchTree bst){
	if(!bst)
		return;
	
	printf("%d ", bst -> data );
	displayPreorder(bst->left);
	displayPreorder(bst->right);
return;
}

void displayPostorder(BinarySearchTree bst){
	if(!bst)
		return;

	displayPreorder(bst->left);
	displayPreorder(bst->right);
	printf("%d ", bst -> data );
return;	
}

int isEmpty(BinarySearchTree bst){
	if(!bst)
		return 1;
	else
		return 0;
}

int countLeaves(BinarySearchTree bst){
	if(!bst)
		return 0;
	if(!(bst->right) && !(bst->left)){
		return 1;	
	}
	return countLeaves(bst->left) + countLeaves(bst->right);
}

int countInternalNodes(BinarySearchTree bst){
	if(!bst)
		return 0;
	
	if(bst->right || bst -> left)
		return 1 + countInternalNodes(bst->right) + countInternalNodes(bst->left);
	else
		return 0;	
}


void printAncestors(BinarySearchTree bst, int data){
	if(!bst)
		return;

	if(bst->data == data)
		return;
	else if(bst -> data < data)
		displayAncestors(bst->right,data);
	else
		displayAncestors(bst->left,data);
	printf("%d <-",bst->data);
return;
}

void displayAncestors(BinarySearchTree bst, int data){

	if(!search(bst,data)){
		return;
	}
	printAncestors(bst,data);
	return;
}	
