class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int n=s.length();
        int prev_sum=1;
        int next_sum=0;
        int ans=0;

        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            prev_sum++;
            else
            {
                ans+=min(prev_sum,next_sum);
                next_sum=prev_sum;
                prev_sum=1;
            }
        }    
        ans+=min(prev_sum,next_sum);
        return ans;
    }
};