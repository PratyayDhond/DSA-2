#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

int main(int argc, char * argv[]){
    Heap heap;
    initHeap(&heap);
    
    int n;
    if(argc < 2){
        printf("Enter no of elements: ");
        scanf("%d",&n);

        int current;
        int t = n;
        while(t--){
            scanf("%d",&current);
            insert(&heap,current);
        }
    }else{
        int temp = 0 ;
        FILE *fptr = fopen(argv[1],"r+");
        fscanf(fptr,"%d",&n);        
        for(int i = 0; i < n; i++){
            fscanf(fptr,"%d",&temp);
            insert(&heap,temp);
        } 
    }


    heapSort(&heap);
    printf("Ascending Order : \n");
    for(int i = 0; i < n; i++)
        printf("%d ",heap.arr[i]);
    printf("\n\n");

    // int * arr = heapSortDesc(&heap);
    // printf("Descending Order : \n");
    // for(int i = 0 ; i < n; i++)
        // printf("%d ",arr[i]);
    // printf("\n");
    

return 0;
}
