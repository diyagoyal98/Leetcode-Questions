class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int ans=-1;
        int count=0;
        multiset<int>s;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                 s.insert(matrix[i][j]);
            }
        }
        for(auto it=s.begin();it!=s.end();it++)
        {
            count++;
            if(count==k)
                ans=*it;
        }
        return ans;
    }
};