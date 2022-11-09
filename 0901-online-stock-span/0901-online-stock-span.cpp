class StockSpanner {
public:
    stack<pair<int,int>>st;
    int idx;
    
    StockSpanner() {
        idx=-1;
    }
    
    int next(int price) {
        idx++;
        
        while(!st.empty() && st.top().second<=price)
        {
            st.pop();
        }
        if(st.empty())
        {
           st.push({idx,price});
           return idx+1; 
        }
        int ans=st.top().first;
        st.push({idx,price});
        return idx-ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */