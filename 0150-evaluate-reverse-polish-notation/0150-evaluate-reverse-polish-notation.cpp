class Solution {
public:
    int evalRPN(vector<string>&s) 
    {
        stack<long>st;
        int n=s.size();
        int ans=0;
        int i=0;
        while(i<n)
        {
            if(s[i]=="+" || s[i]== "-" || s[i]== "*" || s[i]== "/")
            {
                long num1=st.top();
                //cout<<"Num1 "<<num1<<"  ";
                st.pop();
                long num2=st.top();
                //cout<<"Num2  "<<num2<<"   ";
                st.pop();
                
                if(s[i]=="+")
                    st.push(num1+num2);
                else if(s[i]=="-")
                    st.push(num2-num1);
                else if(s[i]=="/")
                    st.push(num2/num1);
                else
                    st.push(num1*num2);
            }
            else
                st.push(stoi(s[i]));
            i++;
        }
        ans=st.top();
        return ans;
    }
};