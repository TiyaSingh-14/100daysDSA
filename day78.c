#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];

    // Initialize matrix with large value
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = INT_MAX;
        }
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int key[MAX];
    int visited[MAX];

    // Initialize
    for(int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0; // start from node 1

    int totalCost = 0;

    for(int i = 1; i <= n; i++) {

        int u = -1;

        // Find minimum key vertex
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += key[u];

        // Update keys
        for(int v = 1; v <= n; v++) {
            if(adj[u][v] != INT_MAX && !visited[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d\n", totalCost);

    return 0;
}
