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
    vector<vector<int>> level(TreeNode *root)
    {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int>tmp;
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                
                tmp.push_back(node->val);
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        ans=level(root);
        return ans;
        
    }
};