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
    
    vector<vector<int>> zigzag(TreeNode *root)
    {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<TreeNode *>q;
        q.push(root);
        bool leftoright=true;
        while(!q.empty())
        {
            int s=q.size();
            vector<int>tmp(s);
            
            for(int i=0;i<s;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                
                int idx=leftoright?i:s-i-1;
                tmp[idx]=node->val;
                
                if(node->left!=NULL)
                    q.push(node->left);
                
                if(node->right!=NULL)
                    q.push(node->right);    
            }
            leftoright=!leftoright;
            ans.push_back(tmp);
        }
        return ans;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        
        return zigzag(root);
    }
};