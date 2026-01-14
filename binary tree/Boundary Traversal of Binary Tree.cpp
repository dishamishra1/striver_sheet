class Solution {
  public:
      bool isLeaf(Node* node)
      {
        return (node->left == NULL && node->right == NULL);
      }

    void lefttraversal(Node *root , vector<int>& ans )
    {
        Node* cur=root->left;
        while(cur!=NULL)
        {
            if(!isLeaf(cur)) ans.push_back(cur->data);
            if(cur->left!=NULL) cur=cur->left;
            else cur=cur->right;
            
        }
    }
    
    void righttraversal(Node *root , vector<int>& ans )
    {
        vector<int> temp;
        Node* cur=root->right;
        while(cur!=NULL)
        {
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right!=NULL) cur=cur->right;
            else cur=cur->left;
        }
        for(int i=temp.size()-1 ; i>=0 ; i--)
        {
            ans.push_back(temp[i]);
        }
        
    }
    void leaftraversal(Node *root , vector<int>& ans )
    {
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        if(root->left!=NULL) leaftraversal(root->left,ans);
        if(root->right!=NULL) leaftraversal(root->right,ans);
    }
    
    
    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        lefttraversal(root,ans);
        leaftraversal(root,ans);
        righttraversal(root,ans);
        return ans;
        
        
    }
};
