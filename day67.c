#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS
void dfs(int v, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while(temp != NULL) {
        if(!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    // push after visiting all neighbors
    stack[++(*top)] = v;
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

    int visited[n];
    for(int i = 0; i < n; i++) visited[i] = 0;

    int stack[n];
    int top = -1;

    // call DFS for all components
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited, stack, &top);
        }
    }

    // print in reverse stack order
    printf("Topological Order: ");
    while(top >= 0) {
        printf("%d ", stack[top--]);
    }

    return 0;
}
