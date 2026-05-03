#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS for cycle detection
int dfs(int v, struct Node* adj[], int visited[], int recStack[]) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while(temp != NULL) {
        int neighbor = temp->vertex;

        if(!visited[neighbor]) {
            if(dfs(neighbor, adj, visited, recStack))
                return 1;
        }
        else if(recStack[neighbor]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for(int i = 0; i < n; i++) adj[i] = NULL;

    // directed edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[n], recStack[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    // check all components
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, adj, visited, recStack)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
