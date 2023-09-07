class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int n=s.length();
        //cout<<n<<"  ";
        int i=0;
        while(s[i]=='0' && i<n)
        {
            //cout<<i<<endl;
            i++;
        }
        
        int one_count=0;
        int zero_count=0;

        for(int j=i;j<n;j++)
        {
            if(s[j]=='0')
            zero_count++;
            else if(s[j]=='1')
            one_count++;

            zero_count=min(one_count,zero_count);   
        }
        return zero_count;
    }
};