#include "graph.h"
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include "stack/stack.h"
#include "queue/linkedQueue.h"

void freeGraph(Graph *g, int index){
    if(!g)
        return;
    
    if(index == 0){
        free(g->arr);
        g->size = 0;
        return;
    }
// error here
    if(index > g->size)  index = g->size - 1;

    for(int i = index; i >= 0; i--){
        free(g->arr[i]);
    }
    free(g->arr);
    g->size = 0;
    return;
}

void initGraph(Graph * g, char * filename){
    FILE *fptr = fopen(filename, "r+");
    if(!fptr)
        return;
    int n = INT_MIN;
    int error = fscanf(fptr,"%d",&n);
    if(error == -1) // EMPTY FILE EOF reached
        return;
    g->size = n;
    g->arr = (int **) malloc(sizeof(int*) * g->size);
    if(!g->arr)
        return;

    for(int i = 0; i < n; i++){
        g->arr[i] = calloc(n,sizeof(int));
        if(!g->arr[i]){ // freeing previous allocated array
            freeGraph(g,i);
            return;
        }
    }
    int temp = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            error = fscanf(fptr,"%d",&temp);
            g->arr[i][j] = temp;
            
                if(error == -1){
                    freeGraph(g,n-1);
                    return; // file contents ended abruptly
                }
        }
    }   
}

void displayGraph(Graph g){
    if(!g.arr)
        return;
    for(int i = 0; i < g.size;i++){
        for(int j = 0; j < g.size; j++){
            printf("%d ",g.arr[i][j]);
        }
        printf("\n");
    }
}

int getDegree(Graph g, int vertex){
    int degree = 0;
    for(int i = 0; i < g.size; i++){
        if(g.arr[vertex][i])    
            degree++;
    }
    return degree;
}

void displayDegreeOfEachVertex(Graph g){
    printf("Vertex -> Degree\n");
    for(int i = 0; i < g.size; i++){
        printf("%d -> %d\n",i,getDegree(g,i));
    }
    return;
}

int isConnected(Graph g){
    int * visited = (int *) calloc(g.size, sizeof(int));
    int startVertex = 0;

    Stack s;
    initStack(&s);
    
    push(&s,0);
    while(!isEmpty(s)){
        int temp = pop(&s);
        visited[temp] = 1;
        for(int i = 0; i < g.size; i++){
            if(g.arr[temp][i] && !visited[i])
                push(&s,i);
        }
    }

    for(int i = 0; i < g.size; i++)
        if(visited[i] == 0)
            return 0;
    return 1;
}

// Check if one vertex is adjacent to another.
int isAdjacent(Graph g, int vertex1, int vertex2){
    if(vertex1 > g.size || vertex2 > g.size)
        return 0;
    if(vertex1 < 0 || vertex2 < 0)
        return 0;
    if(g.arr[vertex1][vertex2])
        return 1;
    return 0;
}

int isVisited(int *visited, int n){
    for(int i = 0; i < n; i++)
        if(!visited[i])
            return i;
    return -1;      // returns the non-visited Index if array is not completely visited else returns -1
}

//Display number of components in the Graph and vertices in each component.
void displayComponents(Graph g){
    int * visited = (int *) calloc(g.size, sizeof(int));
    int startVertex = 0;
    int i = 0;
    printf("\nfirstNode -> SecondNode -  Weight\n");
    for(; i < g.size; i++){ // this loop runs for the edge case that max n components are present in the graph
        int start = isVisited(visited,g.size);
        if(start == -1)
            break;
        

        int hasPrinted = 0;
        Stack s;
        initStack(&s);
        printf("Component %d: \n",i+1);
        push(&s,start);
        while(!isEmpty(s)){
            int temp = pop(&s);
            visited[temp] = i+1;
            for(int i = 0; i < g.size; i++){
                if(g.arr[temp][i] && !visited[i]){
                    printf("   %d -> %d - %d\n",temp,i,g.arr[temp][i]);
                    push(&s,i);
                    visited[i] = i+1;
                    hasPrinted = 1;
                }
            }

            if(!hasPrinted)
                printf("   %d",temp);
        }

        printf("\n\n");

    }    
}

void dfs(Graph g, int start){
    if(!g.arr)
        return;
    if(g.size <= 0)
        return;
    if(start < 0 || start >=g.size)
        return;
    

    int * visited = (int *) calloc(g.size,sizeof(int));
    
    Stack s;
    initStack(&s);

    visited[start] = 0;
    push(&s,start);
    printf("DFS : ");
    while(!isEmpty(s)){
        int temp = pop(&s);
        printf("%d ",temp);

        for(int i = 0; i < g.size; i++){
            if(g.arr[temp][i] && !visited[i]){
                push(&s,i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
    return;
}

void bfs(Graph g, int start){
    if(!g.arr)
        return;
    if(g.size <= 0)
        return;
    if(start < 0 || start >=g.size)
        return;
    
    int * visited = (int *) calloc(g.size,sizeof(int));

    Queue q;
    initQueue(&q);

    enqueue(&q,start);
    visited[start] = 1;

    printf("BFS : ");
    while(!isEmptyQueue(q)){
        int temp = dequeue(&q);
        printf("%d ",temp);

        for(int i = 0; i < g.size; i++){
            if(g.arr[temp][i] && !visited[i]){
                enqueue(&q,i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
    return;
}

void findAndPrintCycles(Graph g, int index,int * visited){
    int * tempVisited = (int *) malloc(sizeof(int ) * g.size);
    if(!tempVisited)
        return;
    visited[index] = 1;
}

void DFSCycles(Graph g, int startIndex, int visited[], int cycles[]){
    visited[startIndex] = 1;
    cycles[g.size] = startIndex;

    for(int i = 0; i < g.size; i++){
        if(g.arr[startIndex][i] && !visited[i] ){
            DFSCycles(g,i,visited,cycles);
        }
    }
    return;
}

void displayCycles(Graph g){

    if(g.size == 0)
        return;
    
    if(!g.arr)
        return;
    
    int * visited = (int *) calloc(g.size, sizeof(int));
    int * cycles = (int *) calloc(g.size, sizeof(int));

    for(int i =0; i < g.size; i++){
        if(!visited[i]){
            DFSCycles(g,i,visited,cycles);
            int j = 0;
            while(cycles[j] != i){
                printf("%d ",cycles[j]);
                j++;
            }
            printf("%d\n",cycles[j]);
        }
    }
}
