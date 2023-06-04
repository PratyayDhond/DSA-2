#ifndef ADJGRAPH_H
#define ADJGRAPH_H

#define CHARACTER_START 65
#define TRUE 1
#define FALSE 0
typedef struct GraphNode{
    int index;
    int weight;
    struct GraphNode* next;
}GraphNode;

typedef struct Graph{
    GraphNode ** col;
    int size;
}Graph;

typedef struct SpanningTree{
    GraphNode **arr;
    int size;
    int totalWeight;
}SpanningTree;


extern char isCharacter;

void initGraph(Graph *g, char * filename);
void displayGraph(Graph g);
void bfs(Graph g, int startIndex);
void dfs(Graph g, int startIndex);
SpanningTree * prims(Graph g, int v);   
SpanningTree * kruskals(Graph g);
void displaySpanningTree(SpanningTree sp);
#endif