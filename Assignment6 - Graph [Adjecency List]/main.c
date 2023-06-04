#include <stdio.h>
#include "adjGraph.h"

char isCharacter;

int main(){

    Graph g;
    initGraph(&g,"question");   
    // initGraph(&g,"question");   
    isCharacter = TRUE;
    // displayGraph(g);
    // printf("BFS : ");
    // bfs(g,0);
    // printf("DFS : ");
    // dfs(g,0);
    // primsAlgorithm(g,0);
    SpanningTree * sp = prims(g,4);
    displaySpanningTree(*sp);
return 0;
}