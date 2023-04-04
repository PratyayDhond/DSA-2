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
	
	insertRecursively(&t,6);
	insertRecursively(&t,3);
	insertRecursively(&t,18);
	insertRecursively(&t,2);
	insertRecursively(&t,5);
	insertRecursively(&t,1);
	insertRecursively(&t,4);
	insertRecursively(&t,15);
	insertRecursively(&t,27);
	insertRecursively(&t,26);
	insertRecursively(&t,23);
	insertRecursively(&t,218);
	insertRecursively(&t,22);
	insertRecursively(&t,25);
	insertRecursively(&t,21);
	insertRecursively(&t,24);
	insertRecursively(&t,215);
	insertRecursively(&t,227);
	insertRecursively(&t,216);
	insertRecursively(&t,16);
	
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
	
	int kid = 2161;
	printf("Ancestors of : %d -> ",kid);
	displayAncestors(t, kid);
	printf("NULL\n");

	return 0;
}
