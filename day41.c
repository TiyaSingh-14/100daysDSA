#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Create queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(Queue* q, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue
int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

// Driver
int main() {
    int N;
    scanf("%d", &N);

    Queue* q = createQueue();
    char op[20];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(q, x);
        }
        else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue(q));
        }
    }

    return 0;
}
