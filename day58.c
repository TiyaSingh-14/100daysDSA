#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Find index in inorder
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree recursively
struct TreeNode* build(int preorder[], int inorder[],
                        int inStart, int inEnd, int* preIndex) {

    if (inStart > inEnd) return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[(*preIndex)++];
    root->left = root->right = NULL;

    if (inStart == inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, root->val);

    root->left = build(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct TreeNode* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct TreeNode* root =
        build(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}
