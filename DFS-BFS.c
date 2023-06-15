#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
typedef struct Graph {
    int numVertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    int i, j;
    for (i = 0; i < numVertices; ++i) {
        for (j = 0; j < numVertices; ++j) {
            graph->adj[i][j] = 0;
        }
    }

    return graph;
}
void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;
}
void dfs(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%c ", 'A'+vertex);


    int i;
    for (i = 0; i < graph->numVertices; ++i) {
        if (graph->adj[vertex][i] == 1 && !visited[i]) {
            dfs(graph, i, visited);
        }

    }


}
void bfs(Graph* graph, int startVertex, int visited2[]) {
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = -1;

    queue[++rear] = startVertex;
    visited2[startVertex] = 1;

    printf("\nBreadth-First Search (BFS): ");

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%c ", 'A'+currentVertex);

        int i;
        for (i = 0; i < graph->numVertices; ++i) {
            if (graph->adj[currentVertex][i] == 1 && !visited2[i]) {
                queue[++rear] = i;
                visited2[i] = 1;
            }
        }
    }
}

int main() {

    int numVertices = 7;
    Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);


    int visited[MAX_VERTICES] = {0};
    int startVertex = 0;

    printf("Depth-First Search (DFS): ");
    dfs(graph, startVertex, visited);
    int visited2[MAX_VERTICES] = {0};


     bfs(graph, startVertex, visited2);


    return 0;

}
