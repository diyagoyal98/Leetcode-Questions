/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parentMapping(TreeNode *root, unordered_map<TreeNode *,TreeNode *>&parent)
    {
        queue<TreeNode *>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode *curr=q.front();
            q.pop();
            
            if(curr->left)
            {
                q.push(curr->left);
                parent[curr->left]=curr;
            }
            
            if(curr->right)
            {
                q.push(curr->right);
                parent[curr->right]=curr;
            }
        }
    }
    vector<int> kdistance(TreeNode *root,TreeNode *target,int k,unordered_map<TreeNode *,TreeNode *>parent)
    {
        vector<int>ans;
        if(root==NULL)
            return ans;
        unordered_map<TreeNode *,bool>visited;
        queue<TreeNode *>q;
        q.push(target);
        visited[target]=true;
        int distance=0;
        
        while(!q.empty())
        {
            int s=q.size();
            if(distance++==k)
                break;
            
            for(int i=0;i<s;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                
                if(curr->right && !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                
                if(parent[curr] && !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
            }
            //distance++;
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode *,TreeNode *>parent;
        parentMapping(root,parent);
            
        vector<int>ans;
        ans=kdistance(root,target,k,parent);
        return ans;
    }
};