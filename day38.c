#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Deque
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

// Create deque
Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// push_front
void push_front(Deque* dq, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->prev = NULL;
    node->next = dq->front;

    if (dq->front != NULL)
        dq->front->prev = node;
    else
        dq->rear = node;

    dq->front = node;
    dq->size++;
}

// push_back
void push_back(Deque* dq, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    node->prev = dq->rear;

    if (dq->rear != NULL)
        dq->rear->next = node;
    else
        dq->front = node;

    dq->rear = node;
    dq->size++;
}

// pop_front
void pop_front(Deque* dq) {
    if (dq->front == NULL) return;

    Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
}

// pop_back
void pop_back(Deque* dq) {
    if (dq->rear == NULL) return;

    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
}

// front
int front(Deque* dq) {
    return dq->front ? dq->front->data : -1;
}

// back
int back(Deque* dq) {
    return dq->rear ? dq->rear->data : -1;
}

// empty
bool empty(Deque* dq) {
    return dq->size == 0;
}

// size
int size(Deque* dq) {
    return dq->size;
}

// clear
void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

// reverse
void reverse(Deque* dq) {
    Node* curr = dq->front;
    Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL) {
        dq->rear = dq->front;
        dq->front = temp->prev;
    }
}

// display
void display(Deque* dq) {
    Node* temp = dq->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
