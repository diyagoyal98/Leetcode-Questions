class Solution {
public:
    string intToRoman(int num) {
        vector<int>n{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string>value{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=12;
        string ans="";
        while(num>0)
        {
            int q=num/n[i];
            num=num%n[i];
            while(q--)
            {
                ans+=value[i];
            }
            i--;
        }
        return ans;
    }
};