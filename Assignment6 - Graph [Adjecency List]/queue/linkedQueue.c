#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include "linkedQueue.h"

void initQueue(Queue *q){
	q->front = NULL;
	q->rear  = NULL;
	q->count = 0;
}

void enqueue(Queue *q, int val){
	QueueNode* nn = (QueueNode*) malloc(sizeof(QueueNode));
	nn->next = NULL;
	nn->prev = NULL;
	nn->data = val;
	if(q->front == NULL && q->rear == NULL)
		q->front = q->rear = nn;
	else{
		q->rear->next = nn;
		q->rear = q->rear->next;
	}	
	return;
}

int dequeue(Queue *q){
	if(isEmptyQueue(*q))
		return INT_MIN;
	int returnValue = q->front->data;
	QueueNode * temp = q->front;
	q->front = q->front->next;
	if(q->front == NULL)
		q->front = q->rear = NULL;
	free(temp);
	return returnValue;
}

int isEmptyQueue(Queue q){
	if( q.front == NULL && q.rear == NULL)
		return true;
	return false;
}
