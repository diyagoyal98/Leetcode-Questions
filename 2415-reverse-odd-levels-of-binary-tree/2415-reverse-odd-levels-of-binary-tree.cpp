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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        if(root==NULL)
            return root;
        
        deque<TreeNode *>q;
        q.push_back(root);
        int level=0;
        
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode *node=q.front();
                q.pop_front();
                if(node->left)
                    q.push_back(node->left);
                if(node->right)
                    q.push_back(node->right);
            }
            level++;
            if(level%2!=0)
            {
                vector<int>tmp;
                
                for(auto it:q)
                {
                    tmp.push_back(it->val);
                }
                int j=tmp.size()-1;
                for(auto it:q)
                {
                    it->val=tmp[j--];
                }
            }
        }
        return root;
    }
};