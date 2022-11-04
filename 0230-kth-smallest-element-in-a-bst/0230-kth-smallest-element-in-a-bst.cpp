/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode *root,int k,int &count,int &ans)
    {
        if(root==NULL)
            return ;
        fun(root->left,k,count,ans);
        count++;
        if(k==count)
        {
            ans=root->val;
            return ;
        }
        fun(root->right,k,count,ans);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        int ans=-1;
        int count=0;
        fun(root,k,count,ans);
        return ans;
    }
};