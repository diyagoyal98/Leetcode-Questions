class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) 
    {
        map<string,int>mp;
        int n=senders.size();
        int a=0;
        for(int i=0;i<n;i++)
        {
            string mes=messages[i];
            int count=1;
            for(int y=0;y<mes.size();y++)
            {
                if(mes[y]==' ')
                    count++;
            }
            mp[senders[i]]+=count;
        }
        priority_queue<pair<int,string>>pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
        }

        return pq.top().second;
    }
};