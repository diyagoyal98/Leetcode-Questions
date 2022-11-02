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
    void maxisum(TreeNode *root,int &ans)
    {
        if(root==NULL)
            return ;
        
        queue<TreeNode *>q;
        q.push(root);
        int maxi=INT_MIN;
        int level=0;
        
        
        while(!q.empty())
        {
            int s=q.size();
            int sum=0;
            for(int i=0;i<s;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                
                
                sum+=node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            level=level+1;
            //cout<<"Sum  "<<sum<<"   ";
            //cout<<"Level "<<level<<"   ";
            if(maxi<sum)
            {
                maxi=sum;
                ans=level;
            }
        }
    }
    
    int maxLevelSum(TreeNode* root) 
    {
        int ans=0;
        
        maxisum(root,ans);
        
        return ans;
    }
};