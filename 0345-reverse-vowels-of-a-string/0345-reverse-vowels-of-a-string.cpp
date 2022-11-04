class Solution {
public:
    int isVowel(char ch)
    {
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }
    string reverseVowels(string s) 
    {
        int n=s.length();
        int i=0,j=n-1;
        vector<int>a;
        for(i=0;i<n;i++)
        {
            if(isVowel(s[i])==1)
                a.push_back(i);
        }
        j=a.size();
        int k=j-1;
        for(i=0,k=j-1;i<j/2 &&k>0;i++,k--)
        {
            swap(s[a[i]],s[a[k]]);
        }
        return s;
    }
};