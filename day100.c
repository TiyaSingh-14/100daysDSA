#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Node;

void merge(Node arr[], int temp[], int count[], int left, int mid, int right) {

    int i = left, j = mid + 1, k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {

        if (arr[j].val < arr[i].val) {
            temp[k++] = j;
            rightCount++;
            j++;
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = i;
            i++;
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = i;
        i++;
    }

    while (j <= right) {
        temp[k++] = j;
        j++;
    }

    for (i = left; i <= right; i++) {
        arr[i] = arr[temp[i]];
    }
}

void mergeSort(Node arr[], int temp[], int count[], int left, int right) {

    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, temp, count, left, mid);
    mergeSort(arr, temp, count, mid + 1, right);
    merge(arr, temp, count, left, mid, right);
}

int main() {

    int n;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    Node arr[n];
    int temp[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
        count[i] = 0;
    }

    mergeSort(arr, temp, count, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}
