class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        set<char> s;

        // Grid check
        for(int i=1; i<=7; i+=3)
            for(int j=1; j<=7; j+=3)
            {
                for(int k=i-1; k<=i+1; k++)
                    for(int l=j-1; l<=j+1; l++)
                        if(board[k][l] != '.')
                            if(s.find(board[k][l]) != s.end())
                                return false;
                            else
                                s.insert(board[k][l]);

                s.clear();
            }

        // Horizontal check
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
                if(board[i][j] != '.')
                    if(s.find(board[i][j]) != s.end())
                        return false;
                    else
                        s.insert(board[i][j]);
            s.clear();
        }

        // Vertical check
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
                if(board[j][i] != '.')
                    if(s.find(board[j][i]) != s.end())
                        return false;
                    else
                        s.insert(board[j][i]);
            s.clear();
        }

        return true;
    }
};

/*
    1,1     1,4     1,7
    4,1     4,4     4,7
    7,1     7,4     7,7
*/
