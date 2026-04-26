#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, x;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create linked list
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Count nodes
    int count = 0;
    temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Output
    printf("%d", count);

    return 0;
}