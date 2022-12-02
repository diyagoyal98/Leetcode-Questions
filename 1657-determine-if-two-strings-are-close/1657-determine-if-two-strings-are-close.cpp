class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        if(word1.size()!=word2.size())
            return false;
        unordered_map<char,int>m1,m2;
        for(int i=0;i<word1.length();i++)
        {
            m1[word1[i]]++;
        }
        
        for(int i=0;i<word2.length();i++)
        {
            if(!m1[word2[i]])
                return false;
            m2[word2[i]]++;
            
        }
        
        vector<int>v1,v2;
        
        auto i1=m1.begin();
        auto i2=m2.begin();
        while(i1!=m1.end() && i2!=m2.end())
        {
            v1.push_back(i1->second);
            //cout<<i1->second<<"  ";
            v2.push_back(i2->second);
            //cout<<i2->second<<"   ";
            i1++;
            i2++;
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        return v1==v2;
    }
};