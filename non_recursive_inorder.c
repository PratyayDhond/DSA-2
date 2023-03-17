#include<stdio.h>
#include<stdlib.h>

//structure for tree
typedef struct node{
struct node*left;
struct node*right;
int data;
}node;
typedef node* BST;

//structure for stack;
typedef struct snode{
node *n;
struct snode*next;
}snode;

typedef snode* stack;

void initstack(stack *s){
*s=NULL;
return;
}

int isfullstack(stack s){
return 0;
}

int isEmptystack(stack s){
if(s==NULL){
    return 1;
}
return 0;
}

void push(stack *s,node*tn){
snode *nn=(snode*)malloc(sizeof(snode));
nn->next=NULL;
nn->n=tn;
if(!(*s)){
    *s=nn;
    return;
}
nn->next=*s;
*s=nn;
return;
}

node *pop(stack *s){
if(!(*s)){
    return NULL;
}
snode *ptr=*s;
node *p=ptr->n;
*s=ptr->next;
free(p);
return p;
}

void inorder(BST t,stack s){
node *p=t;
if(!p){
    return;
}
if(s==NULL){
return ;
}
while(s){
    while(p->left){
        push(&s,p->data);
        p=p->left;
    }
    printf("%d",p->data);
    if(p->right){
        p=p->right;
    }
    else{
        int d=pop(&s);
        printf("%d",d);
    }
}


}

void insert( BST *t, int data ) {
    node *nn=(struct node*)malloc(sizeof(struct node));
    if(!nn){
        return ;
    }
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;

    if(t==NULL){
        t=nn;
        return;
    }
    node*p=*t;
    node*q=NULL;
    while(p){
        q=p;
        if(p->data == data){
            return;
        }
        if(p->data >data){
            p=p->left;
        }
        else{
            p=p->right;
        }
    }
    if(q->data != data){
        if(q->data > data){
            q->left=nn;
        }
        else{
            q->right=nn;
        }
    }
    return ;
}

int main(){
stack s;
BST t;
initstack(&s);
isfullstack(s);
isEmptystack(s);
insert(&s ,10);
insert(&s, 20);
insert(&s, 100);
insert(&s ,103);
insert(&s ,101);
inorder(t,s);
return 0;
}
