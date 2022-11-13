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
    void find_count(vector<int>nums ,int &count)
    {
        vector<pair<int,int>> v;
	    int n=nums.size();
	    for(int i=0;i<n;i++)
        {
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int s=0;
	    for(int i=0;i<n;i++)
        {
	        if(v[i].second==i) continue;
	        else 
            {
	            s++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	   count+=s;
    }    

    void level(TreeNode *root,int &count)
    {
        if(root==NULL)
            return ;
        queue<TreeNode *>q;
        q.push(root);
        
        while(!q.empty())
        {
            int s=q.size();
            vector<int>l;
            for(int i=0;i<s;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                
                if(node->left!=NULL)
                    q.push(node->left);
                
                if(node->right!=NULL)
                    q.push(node->right);
                
                l.push_back(node->val);
            }
            find_count(l,count);
           // l.empty(); 
        }
    }
    int minimumOperations(TreeNode* root) 
    {
        int count=0;
        level(root,count);
        return count;
    }
};