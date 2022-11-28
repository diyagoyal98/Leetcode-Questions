class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        set<int>total;
        map<int,int>count;
        int n=matches.size();
        for(int i=0;i<n;i++)
        {
            int a=matches[i][0];
            int b=matches[i][1];
            total.insert(a);
            total.insert(b);
            count[b]++;
        }
        vector<vector<int>>ans(2);
        for(auto it=total.begin();it!=total.end();it++)
        {
            if(!count.count(*it))
                ans[0].push_back(*it);
            else if(count[*it]==1)
                ans[1].push_back(*it);
        }
        return ans;
    }
};