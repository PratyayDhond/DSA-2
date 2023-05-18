#include "heap.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define EMPTY_HEAP INT_MIN

void initHeap(Heap* heap){
    heap -> size = 1;
    heap -> arr = (int *) malloc(sizeof(int) * heap->size);
    heap -> rearIndex = -1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int isEmpty(Heap h){
    return h.rearIndex == -1;
}
int top(Heap *h){
    if(isEmpty(*h))
        return INT_MIN;

    return h->arr[0];
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

void heapSort(Heap *h){
    int count = h->rearIndex;
    int temp;
    while(h->rearIndex > 0){
        temp = pop(h);
        h->arr[h->rearIndex+1] = temp;
    }
    h->rearIndex = count;

    for(int i = 0; i <= h->rearIndex; i++)
        printf("%d ",h->arr[i]);
    
}

int * heapSortDesc(Heap *h){
    int *ans = (int *) malloc (sizeof(int) * h->rearIndex+1);
    int n = h -> rearIndex+1;
    for(int i = 0; i < n; i++){
        ans[i] = pop(h);
    }
    return ans;
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
            if(h->arr[il] > h->arr[ir])
                maxi = il;
            else
                maxi = ir;
        }
        if(h->arr[i] > h->arr[maxi])
            return;
        else{
            swap(&h->arr[i],&h->arr[maxi]);
            i = maxi;
        }
    il = 2 * i + 1;
    ir = 2 * i + 2;
    }
    return;
}

        
int pop(Heap *heap){
    if(heap -> rearIndex == -1)
        return EMPTY_HEAP;
    int key = heap->arr[0];
    heap->arr[0] = heap-> arr[heap->rearIndex];
    heap->rearIndex--;
    int i = 0;
    heapify(heap);
    return key;
}