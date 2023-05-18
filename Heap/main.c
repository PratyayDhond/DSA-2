#include<stdio.h>
#include "heap.h"

int main(){
    Heap heap;
    initHeap(&heap);

    int n;
    printf("Enter no of elements: ");
    scanf("%d",&n);

    int current;
    int t = n;
    while(t--){
        scanf("%d",&current);
        insert(&heap,current);
    }

    heapSort(&heap);
    // int * ans = heapSortDesc(&heap);
    // for(int i = 0; i < n; i++)
        // printf("%d ",ans[i]);

return 0;
}