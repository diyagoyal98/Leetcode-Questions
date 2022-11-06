class Solution {
public:
    string orderlyQueue(string s, int k) 
    {
        string ans=s;
        if(k==0)
            return s;
        if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }    
        else if(k==1)
        {
            for(int i=0;i<s.length();i++)
            {
                char c=s[0];
                s.erase(s.begin());
                s+=c;
                if(s<ans)
                    ans=s;
            }
            return ans;
        }
        return s;        
    }
};