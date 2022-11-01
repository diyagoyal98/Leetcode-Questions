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
    int ans(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        
        int lf=ans(root->left);
        int rt=ans(root->right);
        
        if(root->val==2)
            return lf||rt;
        else if(root->val==3)
            return lf&&rt;
        else
            return root->val;
    }
    bool evaluateTree(TreeNode* root) 
    {
        return ans(root);    
    }
};