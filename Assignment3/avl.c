#include "avl.h"
#include<stdlib.h>
#include<stdio.h>

#define GOLEFT 99
#define GORIGHT 101
#define ALREADYEXISTS 100

void initAVL(AVL *t){
    *t = NULL;
    return;
}

int getMax(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int getHeight(Node *t){
    if(t == NULL)
        return -1;
    return 1 + getMax(getHeight(t->left),getHeight(t->right));
}

void adjust_bf(AVL *t){
    Node *p = *t;
    while(p){
        p->bf = getHeight(p->left) - getHeight(p->right);
        p = p->parent;
    }
}

// Creates and Initialised a new node
Node * createNewNode(char *name){
    int length = 0;
    char *p = name;
    while(*p != '\0'){
        length++;
        p++;
    }
    Node * nn = (Node *) malloc(sizeof(Node));
    if(!nn) return NULL;

    nn->key = (char *) malloc(sizeof(char) * length+1);
       // copying name to the new node
    p = name;
    char *k = nn->key;
    while(*p != '\0'){
        *k = *p;
        k++; p++;
    }            
    *k = '\0';
    nn->bf = 0;
    nn->left = NULL;
    nn -> right = NULL;
    nn -> parent = NULL;
return nn;
}

int keyCompare(char * name1, char * name2){
    char * p = name1;
    char * q = name2;
    while(*p != '\0' || *q != '\0'){
        if(*p > *q)
            return GOLEFT;
        if(*p < *q)
            return GORIGHT;
        p++;
        q++;
    }
    if(*p == '\0' && *q == '\0')
        return ALREADYEXISTS;
    // if a key is of greater size than the other it definitely has to go right
    else if(*p == '\0' && *q != '\0')
        return GORIGHT;
    // the key is of shorter length so go left
    else if(*p != '\0' && *q == '\0' )
        return GOLEFT;
}

void insertAVL(AVL* avl,char* name){
    Node *t = *avl;
    if(!t){
        Node * nn = createNewNode(name);
        if(!nn) return;
        *avl = nn;
        return;
    }
    int comparison = keyCompare(t->key, name); 
    if(comparison == ALREADYEXISTS)
        return;
    else if(comparison == GOLEFT)
        insertAVL(&(t->left),name);
    else
        insertAVL(&(t->right),name);
} 

void inorderAVL(Node * t){
    if(!t) return;
    inorderAVL(t->left);
    printf("%s ",t->key);
    inorderAVL(t->right);
}