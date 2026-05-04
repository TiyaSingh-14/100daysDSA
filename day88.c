#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;              // first cow placed
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];

            if (count == k)
                return 1;
        }
    }

    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;        // try bigger distance
            low = mid + 1;
        } else {
            high = mid - 1;   // reduce distance
        }
    }

    printf("%d", ans);

    return 0;
}
