#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Push
void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix
int evaluatePostfix(char* expr) {
    Node* stack = NULL;

    char* token = strtok(expr, " ");

    while (token != NULL) {
        // If number
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }
        else {
            int b = pop(&stack);
            int a = pop(&stack);

            int result;
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator\n");
                    return 0;
            }
            push(&stack, result);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

// Driver
int main() {
    char expr[100];

    // Input
    fgets(expr, sizeof(expr), stdin);

    // Remove newline
    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluatePostfix(expr);

    printf("%d", result);

    return 0;
}
