#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct TreeNode* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Pair for queue (node + horizontal distance)
struct Pair {
    struct TreeNode* node;
    int hd;
};

void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    struct Pair queue[1000];
    int front = 0, rear = 0;

    // store values by HD (offset with +500 to avoid negative index)
    int columns[1000][100];
    int colSize[1000] = {0};

    int minHD = 500, maxHD = 500;

    queue[rear++] = (struct Pair){root, 500};

    while (front < rear) {
        struct Pair curr = queue[front++];
        struct TreeNode* node = curr.node;
        int hd = curr.hd;

        columns[hd][colSize[hd]++] = node->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            queue[rear++] = (struct Pair){node->left, hd - 1};

        if (node->right)
            queue[rear++] = (struct Pair){node->right, hd + 1};
    }

    // print from leftmost to rightmost
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < colSize[i]; j++) {
            printf("%d ", columns[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
