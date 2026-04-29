#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to rotate list
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Find length and last node
    struct Node* temp = head;
    int n = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Step 2: Make it circular
    temp->next = head;

    // Step 3: Handle k > n
    k = k % n;

    // Step 4: Find (n-k)th node
    int steps = n - k;
    struct Node* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 5: Set new head and break circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Function to print list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}