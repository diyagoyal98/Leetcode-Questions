class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        /*int count=0;
        int ans=0;
        unordered_map<char,int>mp;
        for(int i=0;i<start.length();i++)
        {
            if(start[i]!=end[i])
            {
                count++;
                mp[start[i]]++;
            }    
        }
        for(auto it:mp)
        {
            //cout<<it.first<<"  "<<it.second<<"  ";
            if(it.second>=2)
                ans++;
        }
        //cout<<ans<<" ";
        for(int i=0;i<bank.size();i++)
        {
            if(end==bank[i] && ans<2)
            {               
                return count;
            }    
        }
        return -1;*/
        
        
        queue<string>q;
        unordered_set<string>visited;
        
        q.push(start);
        visited.insert(start);
        
        int count=0;
        
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string node=q.front();
                q.pop();
                
                if(node==end)
                {
                    return count;
                }
                
                for(char ch:"ACGT")
                {
                    for(int j=0;j<node.size();j++)
                    {
                        string adjnode=node;
                        adjnode[j]=ch;
                        if(!visited.count(adjnode)  && 
                        find(bank.begin(),bank.end(),adjnode)!=bank.end() )
                        {
                            q.push(adjnode);
                            visited.insert(adjnode);
                        }
                    }
                }
            }
            count++;         
        }
        return -1;
    }
};