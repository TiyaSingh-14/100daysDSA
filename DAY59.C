#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Find index in inorder
int find(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct TreeNode* build(int* inorder, int* postorder,
                       int inStart, int inEnd, int* postIndex) {

    if (inStart > inEnd) return NULL;

    struct TreeNode* root =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = postorder[(*postIndex)--];
    root->left = root->right = NULL;

    if (inStart == inEnd) return root;

    int inIndex = find(inorder, inStart, inEnd, root->val);

    // IMPORTANT: build right first
    root->right = build(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = build(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Preorder print
void preorder(struct TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct TreeNode* root =
        build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}
