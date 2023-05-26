typedef struct Graph{
    int **arr;
    int size;
}Graph;

void initGraph(Graph *g, char * filename);
void displayDegreeOfEachVertex(Graph g);
void displayGraph(Graph g);
int isConnected(Graph g);
int isAdjacent(Graph g, int vertex1, int vertex2);
void displayComponents(Graph g);
void dfs(Graph g, int start);
void bfs(Graph g, int start);
