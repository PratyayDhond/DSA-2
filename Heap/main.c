#include<stdio.h>
#include "heap.h"

int main(){
    Heap heap;
    initHeap(&heap);

    int n;
    printf("Enter no of elements: ");
    scanf("%d",&n);

    int current;
    while(n--){
        scanf("%d",&current);
        insert(&heap,current);
    }

    while(heap.rearIndex >= 0){
        printf("%d \n",pop(&heap));
    }
return 0;
}