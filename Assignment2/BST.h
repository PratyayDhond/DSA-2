
typedef struct Node{
    int * arr;
    int size;
}Node;

typedef Node * BST;

void init(BST *t);
void insertBST(BST *t, int key);
void removeBST(BST *t, int key);

// Assignment Functions

int heightOfTheTree(BST t);
int getLeafNodes(BST t);
int isCompleteBST(BST t);
void levelOrder(BST t);
