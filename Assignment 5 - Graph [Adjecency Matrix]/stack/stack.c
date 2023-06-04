#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "stack.h"

void initStack(Stack *s){
    s->top = NULL;
}

Node* newNode(int data){
    Node *nn = (Node*) malloc(sizeof(Node));
    nn ->data = data;
    nn ->next = NULL;
    return nn;
}

int peek(Stack s){
    if(isEmpty(s))
        return INT_MIN;
    return s.top->data;
}
void push(Stack *s, int data){
    Node *nn = newNode(data);
    if(s->top == NULL)
        s->top = nn;
    else{
        nn->next = s->top;
        s->top = nn;
    }
}

int isEmpty(Stack s){
    if(s.top == NULL)
        return 1;
    return 0;
}

int pop(Stack *s){
    if(isEmpty(*s)){
        return INT_MIN;
    }

    Node * temp = s->top;
    s->top = s->top->next;
    int returnValue = temp->data;
    free(temp);
    return returnValue;
}