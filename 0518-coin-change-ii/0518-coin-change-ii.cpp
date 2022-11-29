class Solution {
public:
    /*int fun_change(vector<int>&coins,int amount,int i)
    {
        if(amount==0)
            return 1;
        if(amount<0)
            return 0;
        if(i<0)
            return 0;
        
        return fun_change(coins,amount-coins[i],i)+fun_change(coins,amount,i-1);
    } */   
    int fun_change(vector<int>&coins, int amt)
    {
        vector<vector<int>> dp(amt + 1, vector<int> (coins.size() + 1, 0));
        for(int i = 0 ; i <= coins.size(); i++)
            dp[0][i] = 1;
        
        for(int a = 1; a <= amt; a++)
        {
            for(int ind = 1; ind <= coins.size(); ind++)
            {
                if(a - coins[ind - 1] < 0)
                    dp[a][ind] = dp[a][ind - 1];
                else
                    dp[a][ind] = dp[a][ind - 1] + dp[a - coins[ind - 1]][ind];
            }
        }
        return dp[amt][coins.size()];
    }    
    int change(int amount, vector<int>& coins) 
    {
        /*int n=coins.size()-1;
        return fun_change(coins,amount,n);*/
      
        return fun_change(coins,amount);
    }
};