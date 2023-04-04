#include<stdio.h>
#include "BST.h"
#include<limits.h>

int main(){
    BST t;
    init(&t);
    insertBST(&t, 125);
    insertBST(&t, 5);
    insertBST(&t, 15);
    insertBST(&t, 12);
    insertBST(&t, 123);
    insertBST(&t,2);
    insertBST(&t,1);
    insertBST(&t,3);
    for(int i = 0; i < t->size; i++){
        if(t->arr[i] != INT_MIN){
            printf("%d %d\n", t->arr[i], i);
        }
    }
    printf("height       : %d\n",heightOfTheTree(t));
    printf("Leaf Nodes   : %d\n",getLeafNodes(t));
    printf("Complete BST : %d\n",isCompleteBST(t));
    printf("Level Order Traversal: \n");
    levelOrder(t);
    return 0;
}