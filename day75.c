#include <stdio.h>

#define MAX 10000

int longestZeroSumSubarray(int arr[], int n) {
    
    int sum = 0, maxLen = 0;

    // To store first occurrence of prefix sum
    int hash[2 * MAX + 1];

    // Initialize with -1 (not seen)
    for(int i = 0; i < 2 * MAX + 1; i++) {
        hash[i] = -2;
    }

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum is 0 → from start
        if(sum == 0) {
            maxLen = i + 1;
        }

        int idx = sum + MAX;  // shift for negative sums

        if(hash[idx] != -2) {
            int len = i - hash[idx];
            if(len > maxLen)
                maxLen = len;
        } else {
            hash[idx] = i;  // store first occurrence
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", longestZeroSumSubarray(arr, n));

    return 0;
}
