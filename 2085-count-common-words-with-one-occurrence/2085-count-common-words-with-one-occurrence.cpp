class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) 
    {
        map<string,int>mp1;
        map<string,int>mp2;
        
        for(auto &it:words1)
        {
            mp1[it]++;
        }
        
        for(auto &it:words2)
        {
            mp2[it]++;
        }
        
        int count=0;
        for(auto &it:mp1)
        {
            if(it.second==1)
            {
                auto tmp=mp2.find(it.first);
                if(tmp!=mp2.end() && tmp->second==1)
                    count++;
            }
        }
        return count;
    }
};