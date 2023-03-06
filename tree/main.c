#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

void find(BinarySearchTree t, int key){
	if(search(t,key))
		printf("Found\n");
	else
		printf("Not Found\n");	
return;
}

int main(){
	
	BinarySearchTree t;
	initBst(&t);
	insert(&t,2);
	insert(&t,3);
	insert(&t,1);
	insert(&t,7);
	insert(&t,5);
	
	find(t,5);
	find(t,12);
	find(t,3);
	find(t,7);
	return 0;
}
