#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

// Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for level order
struct Node* queue[MAX];
int front = 0, rear = 0;

void push(struct Node* node) {
    queue[rear++] = node;
}

struct Node* pop() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    push(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* curr = pop();

        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            push(curr->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            push(curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (!root) return;

    struct Node* q[MAX];
    int f = 0, r = 0;

    q[r++] = root;

    int leftToRight = 1;

    while (f < r) {
        int size = r - f;
        int level[size];

        for (int i = 0; i < size; i++) {
            struct Node* node = q[f++];
            level[i] = node->data;

            if (node->left) q[r++] = node->left;
            if (node->right) q[r++] = node->right;
        }

        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}
