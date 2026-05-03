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

    // Array of adjacency lists
    struct Node* adj[n];

    // Initialize lists
    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    int directed;
    printf("Enter 1 for directed graph, 0 for undirected: ");
    scanf("%d", &directed);

    printf("Enter edges (u v):\n");

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // If undirected, add v -> u
        if(!directed) {
            struct Node* newNode2 = createNode(u);
            newNode2->next = adj[v];
            adj[v] = newNode2;
        }
    }

    // Print adjacency list
    printf("\nAdjacency List:\n");
    for(int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while(temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
