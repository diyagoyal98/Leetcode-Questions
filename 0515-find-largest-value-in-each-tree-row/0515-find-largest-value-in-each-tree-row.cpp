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
    void larger(TreeNode *root,vector<int>&ans)
    {
        if(root==NULL)
            return ;
        
        queue<TreeNode *>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int s=q.size();
            vector<int>level;
            for(int i=0;i<s;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                            
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(*max_element(level.begin(), level.end()));
        }
    }
    
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int>ans;
        larger(root,ans);
        return ans;
    }
};