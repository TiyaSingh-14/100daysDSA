#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue for building tree + BFS
struct TreeNode* queue[10000];
int front = 0, rear = 0;

void push(struct TreeNode* node) {
    queue[rear++] = node;
}

struct TreeNode* pop() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order (-1 = NULL)
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    push(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct TreeNode* curr = pop();

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            push(curr->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            push(curr->right);
        }
        i++;
    }

    return root;
}

// Right view
void rightView(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* q[10000];
    int f = 0, r = 0;

    q[r++] = root;

    while (f < r) {
        int size = r - f;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q[f++];

            // last node in this level
            if (i == size - 1)
                printf("%d ", node->val);

            if (node->left) q[r++] = node->left;
            if (node->right) q[r++] = node->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    rightView(root);

    return 0;
}
