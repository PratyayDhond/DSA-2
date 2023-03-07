#include "bst.h"

void find(BinarySearchTree t, int key){
	if(search(t,key))
		printf("%d Found\n",key);
	else
		printf("%d Not Found\n",key);	
return;
}

int main(){
	
	BinarySearchTree t;
	initBst(&t);
	
	insert(&t,6);
	insert(&t,3);
	insert(&t,18);
	insert(&t,2);
	insert(&t,5);
	insert(&t,1);
	insert(&t,4);
	insert(&t,15);
	insert(&t,27);
	insert(&t,16);
	
	find(t,5);
	find(t,12);
	find(t,3);
	find(t,7);

	printf("Displaying Inorder   : ");
	displayInorder(t);
	printf("\nDisplaying Preorder  : ");
	displayPreorder(t);
	printf("\nDisplaying Postorder : ");
	displayPostorder(t);
	printf("\n");
	
	printf("Is tree Empty? %s\n", isEmpty(t) ? "Yes" : "No");
	printf("Number of leaves: %d\n", countLeaves(t));
	printf("Number of internal Nodes: %d\n", countInternalNodes(t));
	
	printf("Ancestors of 16: ");
	displayAncestors(t, 16);
	printf("\n");

	return 0;
}
