#include<stdio.h>
#include "graph.h"

int main(int argc, char * argv[]){
    Graph g;
    if(argc > 1)
        initGraph(&g,argv[1]);
    else
        initGraph(&g,"g1");
    
    // displayGraph(g);
    
    // displayDegreeOfEachVertex(g);
    
    // printf("Is Connected : %s\n",isConnected(g) ? "Yes" : "No");    
    
    // printf("Is Adjacent (%d,%d) : %s\n",0,1,isAdjacent(g,0,1) ? "Yes" : "No");    
    // printf("Is Adjacent (%d,%d) : %s\n",0,3,isAdjacent(g,0,3) ? "Yes" : "No");    
    // printf("Is Adjacent (%d,%d) : %s\n",0,2,isAdjacent(g,0,2) ? "Yes" : "No");  

    displayComponents(g);

    bfs(g,3);
    
    return 0;
}