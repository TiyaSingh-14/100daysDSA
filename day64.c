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
    printf("Enter source vertex: ");
    scanf("%d", &s);

    int visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Queue
    int queue[n];
    int front = 0, rear = 0;

    // Start BFS
    queue[rear++] = s;
    visited[s] = 1;

    printf("BFS Traversal: ");

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        struct Node* temp = adj[node];
        while(temp != NULL) {
            if(!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    return 0;
}
