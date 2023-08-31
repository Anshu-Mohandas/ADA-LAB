#include <stdio.h>
#include <limits.h>

int n;

int min(int key[], int vis[]){
    int min = INT_MAX, index;

    for (int i=0; i<n; i++){
        if (vis[i]==0 && key[i]<min){
            min=key[i];
            index = i;
        }
    }
    return index;
}

int main (){

    int i, j;

    printf ("Enter the number of nodes:\n");
    scanf ("%d",&n);
    int graph [n][n];
    printf ("Enter the graph in the form of adjecency matrix:\n");
    for(i=0; i<n; i++){
        for (j=0; j<n; j++){
            scanf ("%d", &graph[i][j]);
        }
    }

    int mst[n], key[n], vis[n];

    for (i=0; i<n; i++){
        key[i] = INT_MAX;
        vis[i] = 0;
    }  

    key[0]=0;
    mst[0]=-1;

    for (i=0; i<n-1; i++){
        int x = min(key, vis);
        vis[x]=1;
        for (j=0; j<n; j++){
            if (graph[x][j] && vis[j]==0 && graph[x][j]<key[j]){
                mst[j]=x;
                key[j]=graph[x][j];
            } 
        }
    }
    printf ("Graph:\n");
    for (i=1; i<n; i++){
        printf ("%d - %d   %d\n", mst[i], i, graph[i][mst[i]]);
    }

    return 0;
}
