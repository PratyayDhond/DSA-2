#include "adjGraph.h"
#include <stdlib.h>
#include <stdio.h>
#include "stack/stack.h"
#include "queue/linkedQueue.h"
#include <ctype.h>
#include <limits.h>

void appendToAdjecencyList(Graph *g,int row, int index, int weight){
    GraphNode * nn = (GraphNode *) malloc(sizeof(GraphNode));
    if(!nn)
        return;

    nn->next = NULL;
    nn->index = index;
    nn->weight=weight;

    if(!g->col[row]){
        g->col[row] = nn;
        return;
    }
    GraphNode * temp = g->col[row];
    while(temp->next)
        temp = temp->next;
    temp->next = nn;
return;
}

void initGraph(Graph *g, char * filename){
    isCharacter = 0;
    FILE *fptr = fopen(filename,"r+");
    if(!fptr)
        return;
    int n = 0;
    fscanf(fptr,"%d",&n);

    g->col = (GraphNode **) malloc(sizeof(GraphNode *) * n);
    g->size = n;
    for(int i = 0; i<n;i++){
        // g->col[i] = (GraphNode *) malloc(sizeof(GraphNode));
        g->col[i] = NULL;
    }

    int temp = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(fptr,"%d",&temp);
            // alternate approach, pass g->col[i] and just pass j and temp variables.
            if(temp){
                appendToAdjecencyList(g,i,j,temp);
            }
        }
    }
    fclose(fptr);
return;
}

SpanningTree * initAdjecencyList(SpanningTree *s, int n){
    s = (SpanningTree *) malloc (sizeof(SpanningTree));
    s->size = n;
    s->arr = (GraphNode **) malloc(sizeof(GraphNode *) * n);
    for(int i = 0; i<n;i++){
        s->arr[i] = NULL;
    }
    s->totalWeight=0;
return s;
}

void displayGraph(Graph g){

    for(int i = 0; i<g.size;i++){
    GraphNode *temp = g.col[i];
        printf("Vertex %d:\n",i);
        while(temp){
            if(isCharacter)
                printf("%c-%d\n",temp->index+CHARACTER_START,temp->weight);
            else
                printf("%d-%d\n",temp->index,temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
return;
}

// void prims(Graph g,int startIndex){
//     if(!g.col || g.size == 0)
//         return;

//     if(startIndex >= g.size || startIndex < 0)
//         return;

//     Graph SpanningTree;
//     SpanningTree.col = (GraphNode **) malloc(sizeof(GraphNode *) * g.size);
//     SpanningTree.size = g.size;
//     if(!SpanningTree.col)
//         return;

//     for(int i = 0; i < g.size; i++)
//         SpanningTree.col[i] = NULL;

//     short * visited = (short *) calloc(g.size,sizeof(short)); 
    
//     if(!visited){
//         free(SpanningTree.col);
//         return;
//     }
    
//     visited[startIndex] = 1;
//     int min = INT_MAX;
//     int prev_p = s;

//     for(int i = 0; i < g.size -1 ; i++){
//         t[i] = NULL;
//         min = INT_MAX;
//         int minVertex = 0;
//         for(int p =0; p < g.size; P++){
//             if(visited[p]){
//                 for(int j = 0; j < g.size; j++){
//                     if(g.arr[p][j] && !visited[j]){
//                         if(g.arr[p][j] < min){
//                             min = g.arr[p][j];
//                             minVertex = j;
//                             prev_p = p;
//                         }
//                     }
//                 }
//             }
//         }
//         printf("%d %d\n",minVertex,min);
//     }

//     free(visited);
//     return;
// }

void removeExtraChars(int n){
    for(int i = 0; i < n; i++)
        printf("\b \b");
    printf("\n");
}

void bfs(Graph g, int startIndex){

    if(!g.col || g.size == 0)
        return;

    if(startIndex >= g.size)
        return;

    Queue q;
    initQueue(&q);

    short * visited = (short *) calloc(g.size,sizeof(short)); 
    visited[startIndex] = 1;
    enqueue(&q,startIndex);
    while(!isEmptyQueue(q)){
        int temp = dequeue(&q);

        if(isCharacter)
            printf("%c --> ",temp+CHARACTER_START);        
        else
            printf("%d --> ",temp);

        GraphNode * tempNode = g.col[temp];
        while(tempNode){
            if(!visited[tempNode -> index]){
                enqueue(&q,tempNode->index);
                visited[tempNode->index] = 1;
            }
                tempNode = tempNode -> next;
        }
    }
    removeExtraChars(5);
return;   
}

void dfs(Graph g, int startIndex){

    if(!g.col || g.size == 0)
        return;

    if(startIndex >= g.size)
        return;

    Stack s;
    initStack(&s);

    short * visited = (short *) calloc(g.size,sizeof(short)); 
    visited[startIndex] = 1;
    push(&s,startIndex);

    while(!isEmpty(s)){
        int temp = pop(&s);

        if(isCharacter)
            printf("%c --> ",temp+CHARACTER_START);        
        else
            printf("%d --> ",temp);


        GraphNode * tempNode = g.col[temp];
        while(tempNode){
            if(!visited[tempNode -> index]){
                push(&s,tempNode->index);
                visited[tempNode -> index] = 1;
            }
            tempNode = tempNode->next;
        } 
    }
    removeExtraChars(5);
return;
}

void appendToSpanningTree(SpanningTree * sp, int node1,int node2,int weight){

     GraphNode * nn = (GraphNode * ) malloc(sizeof(GraphNode));
     nn->weight = weight;
     nn->index = node2;
     nn->next = NULL;
    if(! sp->arr[node1]){
        sp->arr[node1] = nn;
        return;
    }

    GraphNode * temp = sp->arr[node1];
    while(temp -> next){
        temp = temp -> next;
    }
    temp->next = nn;
return;
}


// void appendToSpanningTree(GraphNode * arr,int node2,int weight){
    // if(!arr)
        // return;
    // 
    //  GraphNode * nn = (GraphNode * ) malloc(sizeof(GraphNode));
    //  nn->weight = weight;
    //  nn->index = node2;
    // 
    // GraphNode * temp = arr;
    // while(temp -> next){
        // temp = temp -> next;
    // }
    // temp->next = nn;
// return;
// }
// 
SpanningTree * prims(Graph g, int v){
    if(g.size == 0 || !g.col || v>= g.size || v < 0)
        return NULL;

    int weightOfTree = 0;
    int * visited = (int *) calloc(g.size, sizeof(int));
    if(!visited)
        return NULL;

    SpanningTree * spanningTree = initAdjecencyList(spanningTree,g.size);
    // printf("%d",spanningTree->size);
    int tempWt = 0;
    for(int i = 0; i < g.size-1; i++){
        int minIndex = -1;
        int min = INT_MAX;
        int node1 = 0;
        int node2 = 0;

        visited[v] = 1;

        for(int j = 0; j < g.size; j++){
            if(visited[j]){
                GraphNode * temp = g.col[j];
                while(temp){
                    if(temp -> weight < min && !visited[temp->index]){
                        min = temp -> weight;
                        minIndex = temp->index;
                        node1 = j;
                        node2 = temp->index;
                    }
                    temp = temp -> next;
                }
            }
        }
        v = minIndex;
        weightOfTree += min;

        appendToSpanningTree(spanningTree,node1,node2,min);
    }
    
    // printf("tree weight -> %d ",weightOfTree);
    spanningTree -> totalWeight = weightOfTree;
    return spanningTree;
}

void displaySpanningTree(SpanningTree sp){
    printf("Total weight : %d\n",sp.totalWeight);
    for(int i = 0; i < sp.size; i++){
        GraphNode * temp = sp.arr[i];
        while(temp){
            if(isCharacter)
                printf("%c %c - %d\n",i+CHARACTER_START,temp->index+CHARACTER_START,temp->weight);
            else
                printf("%d %d - %d\n",i,temp->index,temp->weight);
            temp = temp->next;
        }
    }
}

 /*
void primsAlgorithm(Graph g,int v){
   if(g.size == 0 || v >= g.size || v < 0 )
        return ;
    
    int totalWeight = 0;
    int * visited = (int* )calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited)
    return;

    int tempWeight = 0;
    int n = g.size;
    for(int i = 0 ; i < n ; i++){
        int minIndex = INT_MAX;
        int Value = INT_MAX;
        printf("%d ",v);
        totalWeight += tempWeight  ;
        
        visited[v] = 1;
        for(int j = 0 ; j < n ; j++){
            if(visited[j]){
            GraphNode * temp = g.col[j];
            while(temp){
                if(temp -> weight < Value && !visited[temp -> index]){
                    Value = temp -> weight;
                    minIndex = temp -> index;
                }
                temp = temp -> next;
            }
            }
        }
        v = minIndex;
        tempWeight = Value;
    }
    printf("Weight : %d",totalWeight);
    return ;        
}
 */