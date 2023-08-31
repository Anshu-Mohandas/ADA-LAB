#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min (int a, int b) {
    return a < b ? a : b;
}

int main(){
    int n, graph[10][10], i, j, k;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the weighs of graph in the form of an adjecency matrix:\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) {
            scanf ("%d", &graph[i][j]);
            
            if (i==j) graph[i][j]=0;

            else if (graph[i][j]==0) graph[i][j] = INT_MAX/3;
        }
    }
    for (k=0; k<n; k++) {
        for (i=0; i<n; i++){
            for (j=0; j<n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    for (i=0; i<n; i++){
        printf ("\n");
        for (j=0; j<n; j++) {
            printf ("%d  ", graph[i][j]);
        }
    }

    return 0;
}
