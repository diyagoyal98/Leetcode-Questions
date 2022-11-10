class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>>st;
        string ans;
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && st.top().first==s[i])
            {
                st.top().second++;
                if(st.top().second==k)
                st.pop();
            }    
            else if(st.empty())
            {
                st.push({s[i],1});
            }
            else if(s[i]==st.top().first)
            {
                st.top().second++;
            }
            else
            {
                st.push({s[i],1});
            }
        }
        while(!st.empty())
        {
            int num=st.top().second;
            char c=st.top().first;
            while(num--)
            {
                ans+=c;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};