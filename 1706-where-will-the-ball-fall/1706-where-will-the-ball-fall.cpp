class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,int startindx,vector<int>&ans)
    {
        if(i==grid.size())
        {
            ans[startindx]=j;
            return ;
        }
        if(grid[i][j]==1)
        {
            if(j+1<grid[0].size() && grid[i][j+1]==1)
            {
                dfs(i+1,j+1,grid,startindx,ans);
            }
        }
        else if(grid[i][j]==-1)
        {
            if(j-1>=0 && grid[i][j-1]==-1)
            {
                dfs(i+1,j-1,grid,startindx,ans);
            }
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        vector<int>ans(grid[0].size(),-1);
        for(int i=0;i<grid[0].size();i++)
            dfs(0,i,grid,i,ans);
        return ans;
        
    }
};