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
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root==NULL)
            return NULL;
        if(root->val==val)
            return root;
        
        while(true)
        {
            if(root->val>val)
            {
                if(root->left==NULL)
                    return NULL;
                else
                    if(root->left->val==val)
                        return root->left;
                root=root->left;
            }
            else
            {
                if(root->right==NULL)
                    return NULL;
                else
                    if(root->right->val==val)
                        return root->right;
                root=root->right;
            }
        }
        return NULL;
    }
};