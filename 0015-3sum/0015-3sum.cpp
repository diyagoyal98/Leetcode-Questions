class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        int n=nums.size();
        int j,k;
        sort(nums.begin(),nums.end());
        if(nums[0]>0)
            return ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                break;
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            j=i+1;
            k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    vector<int>tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    ans.push_back(tmp);
                    
                    while(j<k && nums[j]==nums[j+1])
                        j++;
                    while(j<k && nums[k]==nums[k-1])
                        k--;
                     j++;
                     k--;
                }
                else if(sum>0)
                    k--;
                else if(sum<0)
                    j++;
            }     
        }
        return ans;    
    }
};