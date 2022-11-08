class Solution {
public:
    string complexNumberMultiply(string num1, string num2) 
    {
        string a,b;
        for(int i=0;i<num1.size();i++)
        {
            if(num1[i]!='+')
                a+=num1[i];
            else if(num1[i]=='+')
            {
                b=num1.substr(i+1,num1.size()-(i+1)-1);
                break;
            }
        }
        //cout<<a<<"  "<<b<<" ";
        string c="",d;
        for(int i=0;i<num2.size();i++)
        {
            if(num2[i]!='+')
                c+=num2[i];
            else if(num2[i]=='+')
            {
                d=num2.substr(i+1,num2.size()-(i+1)-1);
                break;
            }
        }
        
        //cout<<"  "<<c<<"  "<<d;
        string ans=to_string(stoi(a)*stoi(c)-stoi(b)*stoi(d))+ "+" +                          to_string(stoi(a)*stoi(d)+stoi(b)*stoi(c)) + "i";
        
        return ans;
    }
};