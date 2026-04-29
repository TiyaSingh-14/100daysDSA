#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* createList(int n) {
    if (n == 0) return NULL;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        int value;
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    temp->next = head;

    return head;
}

// Function to traverse circular linked list
void traverseList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createList(n);

    traverseList(head);

    return 0;
}
