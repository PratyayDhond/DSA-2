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
    imbalanceNode->right = rightLeftNode;
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


void adjust_bf(AVL *avl, Node *t,char *name){
    Node *p = t;
    while(p){
        p->bf = getHeight(p->left) - getHeight(p->right);
        printf(" %d ",p->bf);
        if(p->bf > 1){
            // check if the inserted node is greater than q->left
            if(keyCompare(p->left->key, name) == GOLEFT)
                LL_ROTATE(avl,p);
            else
                // continue;
                LR_ROTATE(avl,p);

        }else if(p->bf < -1){
            if(keyCompare(p->right->key,name) == GOLEFT)
                RL_ROTATE(avl,p);
            else{
                RR_ROTATE(avl,p);
            }

        }
        p = p->parent;
    }
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

void removeAVL(AVL* avl, char* name){
    Node * t = * avl;
    if(!t)
        return;
    Node * q = NULL;
    Node * p = t;
    while(p){
        int comparison = keyCompare(p->key,name);
        if(comparison == ALREADYEXISTS)
            break;
        q = p;
        if(comparison == GOLEFT)
            p = p -> left;
        if(comparison == GORIGHT)
            p = p -> right;
    }
    if(p == NULL) // Node not found
        return;

    if(!p->left && !p->right){ // p is leaf node
        if(q == NULL){
            *avl = NULL;
        }else if(q->left == p){
            q->left = NULL;
        }else{
            q->right = NULL;
        }
        free(p);
        adjust_bf(avl,q,name);
        return;
    }

    if(p->left && !p->right){ // p has only left child
        if(!q){
            *avl = p->left;
            p->left->parent = (*avl)-> parent;
        }
        else if(q->left == p){
            q->left = p->left;
            p->left->parent = q;
        }
        else{
            q->right = p->left;
            q->right->parent = q;
        }
        free(p);
        adjust_bf(avl,q,name);
        return;
    }


    if(!p->left && p->right){ // p has only right child
        if(!q){
            p->right->parent = (*avl)->parent;
            *avl = p->right;
        }
        else if(q->left == p){
            q->left = p->right;
            q->left->parent = q;
        }
        else{
            q->right = p->right;
            q->right->parent = q;
        }
        free(p);    
        adjust_bf(avl,q,name);
        return;
    }
    // both child nodes exist
    Node *r = p->left;
    if(!r->right){
        p->left = r->left;
        if(r->left)
            r->left->parent = p;
        strcpy(p->key,r->key);
        free(r);
        adjust_bf(avl,p,name);
        return;
    }

    Node * parent = NULL;
    while(r->right){
        parent = r;
        r = r -> right;
    }
    p->key = r->key;
    parent->right = r->left;
    if(parent->right)   
        parent->right->parent = parent;
    // parent = r->left;
    // traverse(*avl);
    // free(r);
    free(r);  
    adjust_bf(avl,parent,name);
return;
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

void destroy(Node * t){
    if(!t)
        return;
    destroy(t->left);
    destroy(t->right);
    free(t);
return;
}

void destroyAVL(AVL* avl){
    if(!avl)
        return;
    destroy(*avl);
    *avl = NULL;
}