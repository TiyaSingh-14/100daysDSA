#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// min-heapify (end times)
void heapify(int heap[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;
    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int main() {

    int n;
    scanf("%d", &n);

    int** intervals = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        intervals[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    // sort by start time
    qsort(intervals, n, sizeof(int*), compare);

    int heap[n];
    int size = 0;

    // first meeting
    heap[size++] = intervals[0][1];

    for (int i = 1; i < n; i++) {

        // if earliest room is free
        if (heap[0] <= intervals[i][0]) {
            heap[0] = heap[--size];
        }

        // add current meeting end
        heap[size++] = intervals[i][1];

        // rebuild heap
        for (int j = size / 2 - 1; j >= 0; j--)
            heapify(heap, size, j);
    }

    printf("%d", size);

    return 0;
}
