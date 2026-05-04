#include <stdio.h>

int minTime(int* boards, int boardsSize, int k) {
    int low = 0, high = 0;

    // find search range
    for (int i = 0; i < boardsSize; i++) {
        if (boards[i] > low)
            low = boards[i];   // max element
        high += boards[i];     // sum
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int painters = 1;
        int time = 0;

        for (int i = 0; i < boardsSize; i++) {
            if (time + boards[i] <= mid) {
                time += boards[i];
            } else {
                painters++;
                time = boards[i];
            }
        }

        if (painters <= k) {
            ans = mid;
            high = mid - 1;   // try smaller max time
        } else {
            low = mid + 1;    // increase time
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    int result = minTime(boards, n, k);

    printf("%d", result);

    return 0;
}
