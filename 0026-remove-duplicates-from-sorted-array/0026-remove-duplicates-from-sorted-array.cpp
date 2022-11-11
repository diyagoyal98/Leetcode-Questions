class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i,j;
        
        for(i=1,j=0;i<n && j<n ;i++)
        {
            if(nums[i]!=nums[j])
                j++;
            swap(nums[i],nums[j]);
        }
        return j+1;
    }
};