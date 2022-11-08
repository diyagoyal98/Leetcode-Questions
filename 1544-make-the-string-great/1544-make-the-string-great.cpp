class Solution {
public:
    string makeGood(string s) 
    {
        stack<char>st;
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && abs(st.top()-s[i])==32)
                st.pop();
            else
                st.push(s[i]);
        }
        string a;
        while(!st.empty())
        {
            a+=st.top();
            st.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};