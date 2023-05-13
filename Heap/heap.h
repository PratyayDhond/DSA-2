typedef struct Heap
{
    int * arr;
    int size;
    int rearIndex;
}Heap;

void initHeap(Heap* heap);
void insert(Heap *heap, int key);
int pop(Heap *heap);
void heapSort(Heap *h);