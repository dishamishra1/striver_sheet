class Solution {
public:
    int dfsHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int left = dfsHeight(root->left);
        if (left == -1) return -1;

        int right = dfsHeight(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};
