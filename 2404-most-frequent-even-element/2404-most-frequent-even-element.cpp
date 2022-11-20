class Solution {
public:

    int mostFrequentEven(vector<int>& nums) 
    {
        int ans=-1;
        int n=nums.size();
        map<int,int>mp;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            mp[nums[i]]++;
        }
        for(auto &it:mp)
        {
            if(it.second>maxi)
            {
                maxi=it.second;
                ans=it.first;
            }
        }
        
        return ans;
        
    }
};