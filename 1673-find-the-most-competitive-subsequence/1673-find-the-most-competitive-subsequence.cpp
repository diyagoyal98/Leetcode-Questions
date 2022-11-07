class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        stack<int>st;
        int n=nums.size();
        vector<int>ans;
        //st.push(nums[0]);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()>nums[i] && st.size()-1+n-i>=k)
            {
                st.pop();
            }
            st.push(nums[i]);
            
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        ans.resize(k);
        return ans;
    }
};