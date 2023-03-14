#include "bt.h"
#include "node.h"
#define leftDirection 1
#define rightDirection 0
// try recursive search for BST
// in search return count of comparisons instead of found/ not found

int randomGenerator(){
	return rand()%2; // assign the rand() function to random variable.
}

Node* createNewNode(int key){
	Node * nn = (Node*) malloc(sizeof(Node));
	nn->data = key;
	nn->left = nn->right = NULL;
}

void initBT(BT *t){
	*t = NULL;
	return;
}

void insertBT(BT *t, int key){
	if(!*t){
		*t = createNewNode(key);
		return; 
	}
	Node *p = *t;
	
	while(p){

		if(randomGenerator() == leftDirection){
			if(p->left){
				p = p -> left;
			}else{
				p->left = createNewNode(key);
				return;
			}
		}else{
			if(p->right){
				p = p -> right;
			}else{
				p -> right = createNewNode(key);
				return;
			}
		}
	}	
}
void displayBT(BT t){
	if(!t){
		return;
	}
	displayBT(t->left);
	printf("%d ",t->data);
	displayBT(t->right);
return;
}

void displayBTPre(BT t){
	if(!t){
		return;
	}	
	printf("%d ",t->data);
	displayBTPre(t->left);
	displayBTPre(t->right);
return;
}

void searchBT(BT t, int key, int *comparisonCount, int * gotDataFlag){
 	*comparisonCount += 1;
 	if(!t)
	 	return;
	if(t->data == key){
		*gotDataFlag = 1;
		return;
	}
	if(*gotDataFlag == 0)
		searchBT(t->left,key,comparisonCount, gotDataFlag);
	if(*gotDataFlag == 0)
		searchBT(t->right,key,comparisonCount, gotDataFlag);
	return;
}
