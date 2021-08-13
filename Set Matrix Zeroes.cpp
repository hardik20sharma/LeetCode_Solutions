class Solution {
public:
    void setZeroes(vector<vector<int>>& m)
    {
        vector<vector<int>> storage;
        
        for(int i = 0; i < m.size(); i++)
            for(int j = 0; j < m[0].size(); j++)
                if(m[i][j] == 0)
                    storage.push_back( {i, j} );

        for(vector<int> s : storage)
        {
            int x = s[0], y = s[1];
            
            for(int j = 0; j < m[0].size(); j++)
                m[x][j] = 0;
            
            for(int i = 0; i < m.size(); i++)
                m[i][y] = 0;
        }
    }
};
