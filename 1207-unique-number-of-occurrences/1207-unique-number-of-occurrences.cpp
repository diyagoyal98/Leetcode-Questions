class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        set<int>s;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            s.insert(it->second);
        }
        if(s.size()==mp.size())
            return true;
        return false;
    }
};