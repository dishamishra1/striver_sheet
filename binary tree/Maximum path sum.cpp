class Solution {
public:
    int maxroot(TreeNode* root , int& maxi)
    {
        if(root==NULL) return 0;
        int leftsum=max(0,maxroot(root->left, maxi));
        int rightsum=max(0,maxroot(root->right, maxi));
        maxi=max(maxi,root->val + leftsum + rightsum);
        return (root->val) + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) 
    {
        int maxi=INT_MIN;
        maxroot(root,maxi);
        return maxi;
        
    }
};
