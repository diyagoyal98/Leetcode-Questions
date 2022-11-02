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
    int maxwidth(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q; //node,level
        q.push({root,0});
        
        while(!q.empty())
        {
            int s=q.size();
            int min=q.front().second;
            int first,last;
            for(int i=0;i<s;i++)
            {
                TreeNode *node=q.front().first;
                long long curr=q.front().second-min;
                q.pop();
                
                if(i==0)
                    first=curr;
                if(i==s-1)
                    last=curr;
                
                if(node->left)
                    q.push({node->left,2*curr+1});
                if(node->right)
                    q.push({node->right,2*curr+2});
            }   
            ans=max(ans,last-first+1);
        }
        return ans;
    }
    int widthOfBinaryTree(TreeNode* root) 
    {
        return maxwidth(root);    
    }
};