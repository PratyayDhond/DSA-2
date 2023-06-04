typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void initStack(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);
int peek(Stack s);
int isEmpty(Stack s);