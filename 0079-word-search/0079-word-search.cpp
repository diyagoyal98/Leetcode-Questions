class Solution {
public:
    bool dfs(vector<vector<char>>&board,string word,int i,int j,int count)
    {
        if(count==word.size())
            return true;
        if(i==-1 || i==board.size() || j==-1 || j==board[0].size() || board[i][j]!=word[count])
            return false;
        char ch=board[i][j];
        board[i][j]='?';
        bool yippe=dfs(board,word,i,j+1,count+1) || dfs(board,word,i,j-1,count+1) ||
            dfs(board,word,i-1,j,count+1) || dfs(board,word,i+1,j,count+1);
        board[i][j]=ch;
        
        return yippe;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(board,word,i,j,0))
                        return true;
                }
            }
        }
        return false;
    }
};