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
        
        return max(lf,rt)+1;
            
    }
    int maxDepth(TreeNode* root) 
    {
        return check(root);
    }
};