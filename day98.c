#include <stdio.h>
#include <stdlib.h>

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

    int** result = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
        result[i] = (int*)malloc(2 * sizeof(int));

    int idx = 0;

    // start first interval
    result[idx][0] = intervals[0][0];
    result[idx][1] = intervals[0][1];
    idx++;

    for (int i = 1; i < n; i++) {

        int start = intervals[i][0];
        int end = intervals[i][1];

        // overlap → merge
        if (start <= result[idx - 1][1]) {
            if (end > result[idx - 1][1])
                result[idx - 1][1] = end;
        }
        else {
            result[idx][0] = start;
            result[idx][1] = end;
            idx++;
        }
    }

    // print result
    for (int i = 0; i < idx; i++) {
        printf("%d %d\n", result[i][0], result[i][1]);
    }

    return 0;
}
