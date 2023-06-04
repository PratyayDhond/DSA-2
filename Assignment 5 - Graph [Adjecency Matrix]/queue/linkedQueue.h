#define true 1
#define false 0

typedef struct QueueNode{
	struct QueueNode* next;
	struct QueueNode* prev;
	int data;
}QueueNode;

typedef struct Queue{
	QueueNode* front;
	QueueNode* rear;
	int count;
}Queue;

void initQueue(Queue *Q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
int isEmptyQueue(Queue q);