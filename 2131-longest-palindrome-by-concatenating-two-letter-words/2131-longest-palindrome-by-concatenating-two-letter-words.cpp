class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map<string,int>m;
        for(int i=0;i<words.size();i++)
        m[words[i]]++;
        
        int count=0;
        int flag=0;
        
        for(auto i:words)
        {
            string tmp;
                tmp=i;
            if(i[0]==i[1])
            {
                if(m[i]%2==0)
                    count+=2*m[i];
                else
                {
                    count+=2*(m[i]-1);
                    flag=1;
                }
                m[i]=0;
            }
            else
            {
                reverse(tmp.begin(),tmp.end());
            
                if(m[tmp]!=0 && m[i]!=0)
                {
                    count+=4;
                    m[tmp]--;
                    m[i]--;
                }
            }        
        }
        
        if(flag==1)
            count+=2;
        return count;
    }
};