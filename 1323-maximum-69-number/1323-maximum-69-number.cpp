class Solution {
public:
    int maximum69Number (int num) 
    {
        string s=to_string(num);
        for(char c=0;c<s.size();c++)
        {
            if(s[c]=='6')
            {
                s[c]='9';
                break;
            }    
        }
        num=stoi(s);
        return num;
    }
};