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

// DFS function to detect cycle
int dfs(int v, int parent, struct Node* adj[], int visited[]) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while(temp != NULL) {
        int neighbor = temp->vertex;

        if(!visited[neighbor]) {
            if(dfs(neighbor, v, adj, visited))
                return 1;
        }
        else if(neighbor != parent) {
            // visited and not parent → cycle
            return 1;
        }

        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for(int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    // input edges (undirected)
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        struct Node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    int visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // check all components
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, adj, visited)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
