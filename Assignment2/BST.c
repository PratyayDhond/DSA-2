#include "BST.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void init(BST *t){
    *t = (Node *) malloc(sizeof(Node));
    (*t)->arr = NULL;
    (*t)->size = 0;
    return;
}

void insertBST(BST *bst, int key){
    Node *t = *bst;

    // No element present in the tree
    if(t->size == 0){
        t->arr = (int *) malloc(sizeof(int) * (t->size + 1));
        if(!t->arr)
            return;
        t->arr[0] = key;
        t->size++;
        return;
    }


    int p = 0;
    while(p < t->size && t->arr[p] != INT_MIN){
        if(t->arr[p] == key)
            return;
        if(t->arr[p] > key)
            p = 2 * p + 1;
        else
            p = 2 * p + 2;
    }
    // The node to be inserted is in the valid index size of array
    if(p < t -> size){
        t->arr[p] = key;
        return;
    }else{
        t->arr = realloc(t->arr,sizeof(int)* p+1);
        if(!t)
            return;
        int i = t->size;
        while(i<p+1){
            t->arr[i++] = INT_MIN;
        }
        t->size = p+1;
        t->arr[p] = key;
    }    
    return;
}

void removeBST(BST *t, int key);

// Assignment Functions

int heightOfTheTree(BST t){
    
    if(!t)
        return 0;
    int height = 0;
    int i = t->size;
    while(i--){
        if(t->arr[i] != INT_MIN){
            while(i != 0){
                height++;
                i = (i-1)/2;
            }
        }
    }
    return height;
}

int getLeafNodes(BST t){
    if(!t)
        return 0;
    int i = 0;
    int count = 0;
    while(i < t->size){
        if(t->arr[i] != INT_MIN){
            if(2 * i + 1 >= t->size)
                count++;
            else if(t->arr[2*i+1] == INT_MIN && t->arr[2*i+2] == INT_MIN)
                count++;
        }
        i++;
    }
    return count;
}

int isCompleteBST(BST t){
    if(!t)
        return 1; // NULL Tree is Complete BST
    int i = 0;
    int emptyNodeFlag = 0;
    while(i < t->size){
        if(emptyNodeFlag && t->arr[i] != INT_MIN)
            return 0;
        if(t->arr[i] == INT_MIN)
            emptyNodeFlag = 1;
        i++;
    }
    return 1;
}

void levelOrder(BST t){
    if(!t)
        return;
    int i = 0;
    int height = heightOfTheTree(t);

    while(i < t->size){
        for(int j = i;j<i*2+1; j++){
            if(j >= t->size)
                break;
            if(t->arr[j] != INT_MIN)
                printf("%d ",t->arr[j]);
        }
        i = i * 2 + 1;
        printf("\n");
    }
}
