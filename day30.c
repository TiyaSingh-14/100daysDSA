#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Create polynomial
struct Node* createPoly(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        scanf("%d %d", &newNode->coeff, &newNode->exp);
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

// Print polynomial
void printPoly(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        // Print coefficient
        printf("%d", temp->coeff);

        // Print variable part
        if (temp->exp > 1)
            printf("x^%d", temp->exp);
        else if (temp->exp == 1)
            printf("x");

        // Print + if not last term
        if (temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    struct Node* poly = createPoly(n);

    printPoly(poly);

    return 0;
}
