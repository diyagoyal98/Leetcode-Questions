class Solution {
public:
    int myAtoi(string s) {
          int neg=1;
        int n=s.length();
        int i=0;
        int ans=0;
        while(i<n && s[i]==' ')
        {
            i++;
        }
        s=s.substr(i,n-i);
        i=0;
        long tmp=0;
        if(s[i]=='-' || s[i]=='+')
        {
            if(s[i]=='-')
            neg=-1;
            i=1;
        }    
        else
            i=0;
        int MAX=INT_MAX,MIN=INT_MIN ;
        while(i<s.length())
        {
            
            if(!isdigit(s[i]))
                break;
            
            tmp=tmp*10+(s[i]-'0');
            if(neg==-1 && -1*tmp<MIN)
                return MIN;
            if(neg==1 && tmp>MAX)
                return MAX;
            i++;
        }
        return (int)neg*tmp;
    }
    
};