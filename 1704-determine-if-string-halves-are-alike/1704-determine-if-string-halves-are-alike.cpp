class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int n=s.length();
        int c1=0,c2=0;
        int j=n-1;
        //cout<<n/2<<" ";
        for(int i=0,j=n-1;i<n/2 && j>=n/2;i++,j--)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || 
              s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                c1++;
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || 
              s[j]=='A' || s[j]=='E' || s[j]=='I' || s[j]=='O' || s[j]=='U')
                c2++;
        }
        //cout<<c1<<"  "<<c2;
        if(c1==c2)
            return true;
        return false;
    }
};