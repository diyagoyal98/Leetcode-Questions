class Solution {
public:
    int find_ans(int n,vector<int>&dp)
    {
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        
        int ans=n;
        for(int i=1;i*i<=n;i++)
        {
            int tmp=i*i;
            ans=min(ans,1+find_ans(n-tmp,dp));
        }
        
        dp[n]=ans;
        return dp[n];
    }
    int numSquares(int n) 
    {
        vector<int>dp(n+1,-1);
        return find_ans(n,dp);
    }
};