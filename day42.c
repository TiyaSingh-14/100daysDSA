#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Push
void push(int x) {
    stack[++top] = x;
}

// Pop
int pop() {
    return stack[top--];
}

int main() {
    int n, x;

    scanf("%d", &n);

    // Input queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue → stack
    for (int i = 0; i < n; i++) {
        push(dequeue());
    }

    // Step 2: Move stack → queue
    for (int i = 0; i < n; i++) {
        enqueue(pop());
    }

    // Print reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
