#include <stdio.h>
#include <stdbool.h>

bool isMinHeap(int arr[], int n) {
    // We only need to check nodes that have at least one child
    // Internal nodes exist up to index (n-2)/2
    for (int i = 0; i <= (n - 2) / 2; i++) {
        
        // Skip null nodes if represented by -1 (standard for your examples)
        if (arr[i] == -1) continue;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check Left Child
        if (left < n && arr[left] != -1) {
            if (arr[i] > arr[left]) {
                return false;
            }
        }

        // Check Right Child
        if (right < n && arr[right] != -1) {
            if (arr[i] > arr[right]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
