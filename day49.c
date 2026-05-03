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

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder traversal
void inorder(struct TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    inorder(root);

    return 0;
}
