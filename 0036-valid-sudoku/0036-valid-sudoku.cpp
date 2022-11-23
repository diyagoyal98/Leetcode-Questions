class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        
        // declare a set
        
        unordered_set<string> s;
        
        // box number for any cell [i, j] is (i / 3) * + j / 3, taking (3 * 3) boxes
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(mat[i][j] != '.')
                {
                    // if the curr number is already present in set
                    
                    if(s.count("row" + to_string(i) + "*" + to_string(mat[i][j])))
                    {
                        return false;
                    }
                
                    if(s.count("col" + to_string(j) + "*" + to_string(mat[i][j])))
                    {
                         return false;
                    }
                
                    if(s.count("box" + to_string((i / 3) * 3 + j / 3) + "*" + to_string(mat[i][j])))
                    {
                        return false;
                    }
                    
                    // insert the curr number in set with row no., col no., box no.
                
                    s.insert("row" + to_string(i) + "*" + to_string(mat[i][j]));
                
                    s.insert("col" + to_string(j) + "*" + to_string(mat[i][j]));
                
                    s.insert("box" + to_string((i / 3) * 3 + j / 3) + "*" + to_string(mat[i][j]));
                }
            }
        }
        
        return true;
    }
};
