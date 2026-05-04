#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // create buckets
    float** buckets = (float**)malloc(n * sizeof(float*));
    int* size = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
    }

    // distribute elements
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index][size[index]++] = arr[i];
    }

    // sort each bucket
    for (int i = 0; i < n; i++) {
        if (size[i] > 0) {
            insertionSort(buckets[i], size[i]);
        }
    }

    // concatenate
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    // print result
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
