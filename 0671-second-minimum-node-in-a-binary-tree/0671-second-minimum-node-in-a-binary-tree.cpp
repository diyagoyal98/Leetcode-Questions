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
    void inorder(TreeNode *root,set<int> &in)
    {
        if(root==NULL)
            return;
        inorder(root->left,in);
        in.insert(root->val);
        inorder(root->right,in);
        
    }
    int findSecondMinimumValue(TreeNode* root) 
    {
        set<int>in;
        inorder(root,in);
        
        if(in.size()==1)
            return -1;
        auto it=in.begin();
        it++;
        return *it;
    }
};