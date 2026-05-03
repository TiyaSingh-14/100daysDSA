#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS function (recursive)
void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while(temp != NULL) {
        if(!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];

    // initialize adjacency list
    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    int directed;
    printf("Enter 1 for directed, 0 for undirected: ");
    scanf("%d", &directed);

    printf("Enter edges (u v):\n");

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // if undirected
        if(!directed) {
            struct Node* newNode2 = createNode(u);
            newNode2->next = adj[v];
            adj[v] = newNode2;
        }
    }

    int s;
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    int visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(s, adj, visited);

    return 0;
}
