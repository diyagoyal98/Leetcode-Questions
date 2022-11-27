class Solution {
public:
    /*void dfs(int dep,vector<int>&nums,vector<long long>curr,int &ans)
    {
        if(dep==nums.size())
        {
            if(curr.size()<3)
            {
                return ;
            }
            for(int i=1;i<curr.size();i++)
            {
                if(curr[i]-curr[i-1]!=curr[1]-curr[0])
                    return ;
            }
            ans++;
            return ;
        }
        dfs(dep+1,nums,curr,ans);
        curr.push_back(nums[dep]);
        dfs(dep+1,nums,curr,ans);
    }
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        vector<long long>curr;
        dfs(0,nums,curr,ans);
        return (int)ans;
    }*/
    
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int res=0;
        int n=nums.size();
        vector<unordered_map<long long,int>> dp(n);
        for(int end=1;end<n;end++){
            for(int start=0;start<end;start++){
                long long difference=(long long)nums[end]-(long long)nums[start];
                long long sum=0;
                if(dp[start].find(difference)!=dp[start].end()){ 
                    sum=dp[start][difference];
                }
                dp[end][difference]+=(sum+1);  
                res+=sum;
            }
        }
        return res;
    }
    
};