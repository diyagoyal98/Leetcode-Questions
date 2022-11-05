class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* mid;
    TreeNode* last;
    
public:
    void inOrder(TreeNode* root)
    {
        if(root==NULL) return;
        inOrder(root->left);    
        if(prev!=NULL && (root->val < prev->val))
        {
            if(first==NULL)
            {
                first=prev;
                mid=root;
            }
                last=root;
        }
        prev=root;
        inOrder(root->right);
    }
    void recoverTree(TreeNode* root) 
    {
        first=mid=last=NULL;
        prev= new TreeNode(INT_MIN);
        inOrder(root);
        if(first && last) swap(first->val,last->val);
        else if(first && mid)swap(first->val, mid->val);
    }
};