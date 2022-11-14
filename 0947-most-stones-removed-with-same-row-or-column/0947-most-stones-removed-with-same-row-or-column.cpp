class Solution 
{
    private:
    vector<int> row;
    vector<int> col;
    vector<int> fa;
    
    public:
    int find(int x)
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void Union(int p, int q)
    {
        int fp = find(p);
        int fq = find(q);
        if(fp != fq)
        {
            fa[fp] = fq;
        }
    }
    
    int removeStones(vector<vector<int>>& stones)
    {
        int ans = 0;
        int n = stones.size();
        fa.resize(n);
        row.resize(10000,-1);
        col.resize(10000,-1);
        for(int i = 0; i < n; i++)
        {
            int x = stones[i][0];
            int y = stones[i][1];
            fa[i] = i;
            if(row[x] != -1)
            {
                Union(row[x],i);
            }
            if(col[y] != -1)
            {
                Union(col[y],i);
            }
            row[x] = i;
            col[y] = i;
        }
        for(int i = 0; i < n; i++)
        {
            if(i == find(i))
            {
                ans++;
            }
        }
        ans = n - ans;
        return ans;
    }
    
};