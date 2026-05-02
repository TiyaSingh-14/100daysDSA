#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify Up
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}

// Heapify Down
void heapifyDown(int i) {
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
}

// Insert
void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// Peek
int peek() {
    if (size == 0) return -1;
    return heap[0];
}

// Extract Min
int extractMin() {
    if (size == 0) return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);

    return min;
}

// Driver
int main() {
    int N;
    scanf("%d", &N);

    char op[20];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
        else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}
