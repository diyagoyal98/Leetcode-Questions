class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
       int i,j,l,r,flag=0;
        vector<int>ans;
        l=nums.size();
        for(i=0;i<l;i++)
        {
            for(j=i+1;j<l;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    flag=-1;
                    break;
                }
            }
            if(flag==-1)
                break;
        }
        return ans;
    
    }
};