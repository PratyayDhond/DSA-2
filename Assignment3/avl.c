#include "avl.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

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
    int comparison = strcmp(name1,name2);
    if(comparison == 0)
        return ALREADYEXISTS;
    if(comparison > 0)
        return GOLEFT;
    else
        return GORIGHT;
}

void LL_ROTATE(AVL *t, Node *imbalancedNode){
    Node * leftNode = imbalancedNode->left;
    Node * leftRightNode = leftNode->right;
    Node * ImbalanceParent = imbalancedNode->parent;
    leftNode->parent = ImbalanceParent;

    if(ImbalanceParent == NULL)
        *t = leftNode;
    else{
        imbalancedNode->parent = leftNode;
        if(ImbalanceParent->right == imbalancedNode)
            ImbalanceParent->right = leftNode;
        else
            ImbalanceParent->left = leftNode;
    }
    imbalancedNode->parent = leftNode;
    leftNode->right = imbalancedNode;
    imbalancedNode->left = leftRightNode;
    if(leftRightNode)
        leftRightNode->parent = imbalancedNode;
    return;
}

void RR_ROTATE(AVL *t, Node *imbalanceNode){
    Node * rightNode = imbalanceNode->right;
    Node * rightLeftNode = rightNode->left;
    Node * imbalaceParent = imbalanceNode->parent;
    rightNode->parent = imbalaceParent;
    if(imbalaceParent == NULL){
        *t = rightNode;
    }else{
        imbalanceNode->parent = rightNode;
        if(imbalaceParent -> right == imbalanceNode)
            imbalaceParent->right = rightNode;
        else
            imbalaceParent->left = rightNode;
    }
    imbalanceNode->parent = rightNode;
    rightNode->left = imbalanceNode;
    imbalanceNode->right
     = rightLeftNode;
    if(rightLeftNode)
        rightLeftNode->parent = imbalanceNode;
    return;
}

void LR_ROTATE(AVL *t, Node * imbalanceNode){
    RR_ROTATE(t,imbalanceNode->left);
    LL_ROTATE(t,imbalanceNode);
}

void RL_ROTATE(AVL *t, Node* imbalanceNode){
    LL_ROTATE(t,imbalanceNode->right);
    RR_ROTATE(t,imbalanceNode);
}

void insertAVL(AVL* avl,char* name){
    Node *t = *avl;
    if(!t){ 
        Node * nn = createNewNode(name);
        if(!nn) return;
        *avl = nn;
        return;
    }
    Node *p = t;
    Node *q = NULL;
    while(p){
        int comparison = keyCompare(p->key, name); 
        if(comparison == ALREADYEXISTS)
            return;
        q = p;
        if(comparison == GOLEFT){
            p = p->left;
        }else{
            p = p -> right;
        }
    }
    if(keyCompare(q->key,name) == GOLEFT){
        q->left = createNewNode(name);
        q->left->parent = q;
    }
    else{
        q->right = createNewNode(name);
        q->right->parent = q;
    }    

    while(q){

        q->bf = getHeight(q->left) - getHeight(q->right);
        if(q->bf == 0)
            return;
        // Insertion was done in the left
        else if(q->bf > 1)
        {
            // check if the inserted node is greater than q->left
            if(keyCompare(q->left->key, name) == GOLEFT)
                LL_ROTATE(avl,q);
            else
                // continue;
                LR_ROTATE(avl,q);

        }else if(q->bf < -1){
            if(keyCompare(q->right->key,name) == GOLEFT)
                RL_ROTATE(avl,q);
            else{
                RR_ROTATE(avl,q);
            }

        }
        q->bf = getHeight(q->left) - getHeight(q->right);

        q = q->parent;
    }

} 

void traverse(Node * t){
    if(!t) return;
    traverse(t->left);
    printf("%s -> ",t->key);
    if(t->parent)
        printf("%s -> ",t->parent->key);
    else
        printf("NULL -> ");
    printf("%d \n",t->bf);
    traverse(t->right);
}