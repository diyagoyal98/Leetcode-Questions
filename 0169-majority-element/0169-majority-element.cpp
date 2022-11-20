class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        int ans;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>n/2)
            {
                ans=it->first;
              
            }
            //cout<<it->first<<"   "<<it->second<<"        ";
        }
        return ans;
    }
};