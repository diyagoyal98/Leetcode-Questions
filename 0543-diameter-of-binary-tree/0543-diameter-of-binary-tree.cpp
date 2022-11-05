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
    int finddiameter(TreeNode *root,int &ans)
    {
        if(root==NULL)
            return 0;
        
        int l=finddiameter(root->left,ans);
        int r=finddiameter(root->right,ans);
        
        ans=max(ans,l+r); 
        
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int dia=0;
        
        finddiameter(root,dia);
        
        return dia;
    }
};