#include "heap.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define EMPTY_HEAP INT_MIN

void initHeap(Heap* heap){
    heap -> size = 100;
    heap -> arr = (int *) malloc(sizeof(int) * heap->size);
    heap -> rearIndex = -1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void insert(Heap *heap, int key){
    if(!heap)
        return;
    
    // if heap is full
    if(heap -> rearIndex == heap -> size - 1){
        heap -> size *= 2;
        heap -> arr = (int *) realloc(heap->arr, sizeof(int) * heap->size);
    }

    heap->rearIndex++;
    heap->arr[heap->rearIndex] = key;
    int i = heap -> rearIndex;
    do{
        // current is greater than parent ; then swap
        if(heap->arr[i] > heap->arr[(i-1)/2]){
            swap(&heap->arr[i],&heap->arr[(i-1)/2]);
        }else{
            break;
        }
        i = (i-1)/2;
    }while(i > 0); // i >= 0
}

int pop(Heap *heap){
    if(heap -> rearIndex == -1)
        return EMPTY_HEAP;
    int key = heap->arr[0];
    heap->arr[0] = heap-> arr[heap->rearIndex];
    heap->rearIndex--;
    int i = 0;
    while(2*i+2 <= heap->rearIndex){
        if(heap->arr[i] >= heap->arr[2*i+1] && heap->arr[i] >= heap->arr[2*i+2])
            break;
        if(heap -> arr[2*i+1] > heap -> arr[2*i+2]){
            swap(&heap->arr[i],&heap->arr[2*i+1]);
            i = 2 * i + 1;
        }else{
            swap(&heap->arr[i],&heap->arr[2*i+2]);
            i = 2 * i + 2;
        }        
    }
    return key;
}