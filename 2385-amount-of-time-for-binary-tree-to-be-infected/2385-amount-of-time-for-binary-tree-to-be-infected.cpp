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
    TreeNode * parentmapping(TreeNode *root, unordered_map<TreeNode *,TreeNode *>&parent,int start)
    {
        queue<TreeNode *>q;
        q.push(root);
        TreeNode *st;
        
        while(!q.empty())
        {
            TreeNode * curr=q.front();
            if(curr->val==start)
                st=curr;
            q.pop();
            
            if(curr->left)
            {
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return st;
    }
    int TimeInfect(TreeNode *root,TreeNode *st,unordered_map<TreeNode *,TreeNode *>parent)
    {
        unordered_map<TreeNode *,bool>visited;
        queue<TreeNode *>q;
        q.push(st);
        visited[st]=true;
        int infTime=0;
        
        while(!q.empty())
        {
            int s=q.size();
            int time=0;
            
            for(int i=0;i<s;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                
                //check for left
                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left]=true;
                    time=1;
                }
                
                //check for right
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right]=true;
                    time=1;
                }
                
                //check for parent
                if(parent[curr] && !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                    time=1;
                }
            }
            if(time==1)
                infTime++;
        }
        return infTime;
    }
    int amountOfTime(TreeNode* root, int start) 
    {
        unordered_map<TreeNode *,TreeNode *>parent;
        TreeNode *st;
        st=parentmapping(root,parent,start);
        
        return TimeInfect(root,st,parent);
    }
};