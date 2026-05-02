#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front, rear, size;
} CircularQueue;

// Create queue
CircularQueue* createQueue(int size) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->size = size;
    q->arr = (int*)malloc(size * sizeof(int));
    q->front = q->rear = -1;
    return q;
}

// Enqueue
void enqueue(CircularQueue* q, int value) {
    if ((q->rear + 1) % q->size == q->front) {
        return; // Queue full (ignored as per problem)
    }

    if (q->front == -1) { // first element
        q->front = 0;
    }

    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
}

// Dequeue
void dequeue(CircularQueue* q) {
    if (q->front == -1) return; // empty

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
}

// Display
void display(CircularQueue* q) {
    if (q->front == -1) return;

    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
}

// Driver
int main() {
    int n, m, x;

    scanf("%d", &n);

    CircularQueue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(q, x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue(q);
    }

    display(q);

    return 0;
}
