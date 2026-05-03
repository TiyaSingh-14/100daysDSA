#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

// Min heap node
typedef struct {
    int vertex, dist;
} HeapNode;

HeapNode heap[10000];
int size = 0;

// Swap
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Push into heap
void push(int v, int dist) {
    heap[size].vertex = v;
    heap[size].dist = dist;
    int i = size++;

    while(i > 0 && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Pop min
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while(2*i + 1 < size) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if(right < size && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if(smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[MAX] = {NULL};

    // Build graph
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->v = v;
        newNode->w = w;
        newNode->next = adj[u];
        adj[u] = newNode;

        // Undirected
        newNode = (Node*)malloc(sizeof(Node));
        newNode->v = u;
        newNode->w = w;
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    for(int i = 1; i <= n; i++) dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while(size > 0) {
        HeapNode curr = pop();
        int u = curr.vertex;

        for(Node* temp = adj[u]; temp != NULL; temp = temp->next) {
            int v = temp->v;
            int w = temp->w;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
        }
    }

    // Output distances
    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
