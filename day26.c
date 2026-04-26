#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Insert at end
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
        return newNode;

    struct Node* temp = head;

    // Move to last node
    while (temp->next != NULL)
        temp = temp->next;

    // Link new node
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Traverse forward
void printForward(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, x;
    struct Node* head = NULL;

    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    // Output
    printForward(head);

    return 0;
}