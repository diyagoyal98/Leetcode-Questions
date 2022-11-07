class Solution {
public:
    string frequencySort(string s) 
    {
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        
        priority_queue<pair<int,char>>pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
        }
        string ans="";
        while(!pq.empty())
        {
            int a=pq.top().first;
            char b= pq.top().second;
            for(int i=0;i<a;i++)
            {
                ans+=b;
            }
            pq.pop();
        }
        return ans;
    }
};