#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Check mirror condition
int isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (!t1 && !t2) return 1;
    if (!t1 || !t2) return 0;
    if (t1->val != t2->val) return 0;

    return isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main function
int isSymmetric(struct TreeNode* root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}
