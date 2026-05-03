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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for(int i = 0; i < n; i++) adj[i] = NULL;

    int indegree[n];
    for(int i = 0; i < n; i++) indegree[i] = 0;

    // input directed edges
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // u → v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++;  // increase indegree
    }

    // queue
    int queue[n];
    int front = 0, rear = 0;

    // push all nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    printf("Topological Order: ");

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];
        while(temp != NULL) {
            int neighbor = temp->vertex;
            indegree[neighbor]--;

            if(indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    // cycle check
    if(count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }

    return 0;
}
