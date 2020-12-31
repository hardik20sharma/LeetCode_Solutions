class Solution {
public:
    void gameOfLife(vector<vector<int>>& b)
    {    
        vector<vector<int>> sol (28, vector<int> (28, 0) );

        for(int i=0; i<b.size(); i++)
            for(int j=0; j<b[0].size(); j++)
                sol[i+1][j+1] = b[i][j];
        
        for(int i=1; i<=b.size(); i++)
            for(int j=1; j<=b[0].size(); j++)
            {
                int live_neighbors = sol[i-1][j-1] + sol[i-1][j] + sol[i-1][j+1] +
                                     sol[i][j-1]       +           sol[i][j+1] +
                                     sol[i+1][j-1] + sol[i+1][j] + sol[i+1][j+1];
                
                if(b[i-1][j-1])
                    (live_neighbors < 2 || 3 < live_neighbors) ? b[i-1][j-1] = 0 : b[i-1][j-1] = 1;
                else
                    if(live_neighbors == 3)
                        b[i-1][j-1] = 1;
            }
    }
};
