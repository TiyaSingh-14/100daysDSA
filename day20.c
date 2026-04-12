#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int sum;
    int count;
    struct Node* next;
} Node;
int hash(int key, int size) {
    if (key < 0) key = -key;
    return key % size;
}

void insert(Node** table, int size, int sum) {
    int index = hash(sum, size);
    Node* temp = table[index];

    while (temp != NULL) {
        if (temp->sum == sum) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->count = 1;
    newNode->next = table[index];
    table[index] = newNode;
}
int getCount(Node** table, int size, int sum) {
    int index = hash(sum, size);
    Node* temp = table[index];

    while (temp != NULL) {
        if (temp->sum == sum)
            return temp->count;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int size = 1000; 
    Node** table = (Node**)calloc(size, sizeof(Node*));

    int prefixSum = 0;
    int count = 0;
    insert(table, size, 0);

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        count += getCount(table, size, prefixSum);
        insert(table, size, prefixSum);
    }

    printf("%d\n", count);

    return 0;
}