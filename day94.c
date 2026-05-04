#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    int max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    // frequency array
    int freq[max + 1];
    for (int i = 0; i <= max; i++)
        freq[i] = 0;

    // count frequencies
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // build output array
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (freq[i] > 0) {
            arr[index++] = i;
            freq[i]--;
        }
    }

    // print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
