class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int i,j,n=nums.size();
        if(k==1) 
            return nums;
        priority_queue<pair<int,int>> pq;
        for(i=0;i<k && i<n;i++) 
            pq.push({nums[i],i});
        vector<int> res;
        res.push_back(pq.top().first);
        j=i; i=1;
        while(j<n)
        {
          pq.push({nums[j],j});
          while(!pq.empty()&&pq.top().second<i) pq.pop();
          res.push_back(pq.top().first);
            i++; j++;
        }
        return res;
    }
};