#include "heap.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define EMPTY_HEAP INT_MIN

void initHeap(Heap* heap){
    heap -> size = 1;
    heap -> arr = (Data *) malloc(sizeof(Data) * heap->size);
    heap -> rearIndex = -1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int isEmptyHeap(Heap h){
    return h.rearIndex == -1;
}
Data * top(Heap *h){
    if(isEmptyHeap(*h))
        return NULL;

    Data * data = (Data *) malloc(sizeof(Data));
    data->node1  = h->arr[0].node1; 
    data->node2  = h->arr[0].node2; 
    data->weight = h->arr[0].weight; 
    return data;
}

void insert(Heap *heap, int node1,int node2,int weight){
    if(!heap)
        return;
    
    // if heap is full
    if(heap -> rearIndex == heap -> size - 1){
        heap -> size *= 2;
        heap -> arr = (Data *) realloc(heap->arr, sizeof(Data) * heap->size);
    }

    heap->rearIndex++;
    heap->arr[heap->rearIndex].node1  = node1;
    heap->arr[heap->rearIndex].node2  = node2;
    heap->arr[heap->rearIndex].weight = weight;
    int i = heap -> rearIndex;
    do{
        // current is greater than parent ; then swap
        if(heap->arr[i].weight < heap->arr[(i-1)/2].weight){
            swap(&heap->arr[i].node1,&heap->arr[(i-1)/2].node1);
            swap(&heap->arr[i].node2,&heap->arr[(i-1)/2].node2);
            swap(&heap->arr[i].weight,&heap->arr[(i-1)/2].weight);
        }else{
            break;
        }
        i = (i-1)/2;
    }while(i > 0); // i >= 0
}

void heapify(Heap *h){
    int i = 0;
    int il,ir;
    int max,maxi;
    il = 2 * i + 1;
    ir = 2 * i + 2;
    while(il <= h->rearIndex){
        if(ir > h->rearIndex)
            maxi = il;
        else{
            if(h->arr[il].weight < h->arr[ir].weight)
                maxi = il;
            else
                maxi = ir;
        }
        if(h->arr[i].weight < h->arr[maxi].weight)
            return;
        else{
            swap(&h->arr[i].node1,&h->arr[maxi].node1);
            swap(&h->arr[i].node2,&h->arr[maxi].node2);
            swap(&h->arr[i].weight,&h->arr[maxi].weight);
            i = maxi;
        }
    il = 2 * i + 1;
    ir = 2 * i + 2;
    }
    return;
}

        
Data * popFromHeap(Heap *heap){
    if(heap -> rearIndex == -1)
        return NULL;
    Data * key = (Data *) malloc(sizeof(Data));
    
    key->node1  = heap->arr[0].node1;
    key->node2  = heap->arr[0].node2;
    key->weight = heap->arr[0].weight;
    
    heap->arr[0] = heap-> arr[heap->rearIndex];
    heap->rearIndex--;
    int i = 0;
    heapify(heap);
    return key;
}