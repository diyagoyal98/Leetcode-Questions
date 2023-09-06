class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        vector<vector<string>>ans;
        sort(products.begin(),products.end());
        int n=searchWord.size();
        int m=products.size();
      
        string ch="";
        for(int i=0;i<n;i++)
        {
            ch+=searchWord[i];
            vector<string>st;
            for(int j=0;j<m;j++)
            {
                string tmp=products[j];
                if(tmp.substr(0,ch.length())==ch)
                st.push_back(tmp);
                if(st.size()==3) break;
            }
            ans.push_back(st);
        }    
        return ans;
    }
};