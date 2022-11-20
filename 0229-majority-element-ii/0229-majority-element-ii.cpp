class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int>ans;
        int n=nums.size();
        map<int,int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        float target=n/3;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>target)
            {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};