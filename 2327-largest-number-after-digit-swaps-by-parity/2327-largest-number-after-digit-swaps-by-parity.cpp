class Solution {
public:
  
    int largestInteger(int num) 
    {
        vector<int>even;
        vector<int>odd;

        string s=to_string(num);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int d=s[i]-'0';
            if(d%2==0)
            even.push_back(d);
            else
            odd.push_back(d);
        }
        sort(even.begin(),even.end(),greater<int>());
        sort(odd.begin(),odd.end(),greater<int>());
        int j=0,k=0;
        int ans=0;
        for(int i=0;i<even.size();i++)
        {
            cout<<even[i]<<"   ";
        }
        cout<<endl;
        for(int i=0;i<odd.size();i++)
        {
            cout<<odd[i]<<"   ";
        }

        for(int i=0;i<n;i++)
        {
            ans=ans*10;
            if((s[i]-'0')%2 ==0  && j<even.size())
            {
                //cout<<s[i]<<"   ";
                ans+=even[j++];
            }
            else
            {
                //cout<<s[i]<<"   ";
                ans+=odd[k++];
            }
        }
        return ans;
    }
};