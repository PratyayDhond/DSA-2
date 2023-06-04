typedef struct Data{
    int node1;
    int node2;
    int weight;
}Data;

typedef struct Heap
{
    Data * arr;
    int size;
    int rearIndex;
}Heap;

void initHeap(Heap* heap);
void insert(Heap *heap, int node1,int node2,int weight);
Data * popFromHeap(Heap *heap);