typedef struct Node{
    char* key;
    short int bf; // balance factor
    struct Node * left;
    struct Node * right;
    struct Node * parent;
}Node;

typedef Node * AVL;

void initAVL(AVL*);
void insertAVL(AVL*,char*); 
void traverse(AVL);
int getHeight(Node*);
void removeNodeFromAVL(AVL*);
Node* searchInAVL(AVL);