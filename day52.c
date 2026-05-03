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

// Build tree (level order)
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

// Find LCA
struct TreeNode* LCA(struct TreeNode* root, int p, int q) {
    if (root == NULL) return NULL;

    if (root->val == p || root->val == q)
        return root;

    struct TreeNode* left = LCA(root->left, p, q);
    struct TreeNode* right = LCA(root->right, p, q);

    if (left && right) return root;

    return left ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    int p, q;
    scanf("%d %d", &p, &q);

    struct TreeNode* ans = LCA(root, p, q);

    if (ans)
        printf("%d\n", ans->val);

    return 0;
}
