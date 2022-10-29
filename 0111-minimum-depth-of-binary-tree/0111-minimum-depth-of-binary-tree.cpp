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
    int check(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int lf=check(root->left);
        int rt=check(root->right);
        if(lf==0)
            return 1+rt;
        else if(rt==0)
            return 1+lf;
        return 1+min(lf,rt);
    }
    int minDepth(TreeNode* root) 
    {
        return check(root);    
    }
};