class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>>ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<n;i++)
        {
            if(ans.empty())
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                vector<int>&tmp=ans.back();
                int prev_end=tmp[1];
                int curr_start=intervals[i][0];
                if(curr_start<=prev_end)
                {
                    tmp[1]=max(intervals[i][1],prev_end);
                }
                else
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};