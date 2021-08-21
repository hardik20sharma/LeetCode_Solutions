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

/* ============================================================================================================================================= */
/* ============================================================================================================================================= */
/* -------------------------------------------------------- ANOTHER APPROACH ------------------------------------------------------------------- */
/* ============================================================================================================================================= */
/* ============================================================================================================================================= */

class Solution {

    int numInCell(vector<vector<char>> &board, int row, int col)
    {
        if(board[row][col] == '.')
            return 0;

        return (board[row][col] - '0');
    }

    bool isValidRow(vector<vector<char>> &board, int row)
    {
        vector<bool> store(9, false);

        for(int j = 0; j < 9; j++)
            if(numInCell(board, row, j))
                if(store[ numInCell(board, row, j) ] == true)
                    return false;
                else
                    store[ numInCell(board, row, j) ] = true;

        return true;
    }

    bool isValidCol(vector<vector<char>> &board, int col)
    {
        vector<bool> store(9, false);

        for(int i = 0; i < 9; i++)
            if(numInCell(board, i, col))
                if(store[ numInCell(board, i, col) ] == true)
                    return false;
                else
                    store[ numInCell(board, i, col) ] = true;

        return true;
    }
    
    bool isValidBox(vector<vector<char>> &board, int row, int col)
    {
        vector<bool> store(9, false);
        
        for(int i = row-1; i <= row+1; i++)    
            for(int j = col-1; j <= col+1; j++)
                if(numInCell(board, i, j))
                    if(store[ numInCell(board, i, j) ] == true)
                        return false;
                    else
                        store[ numInCell(board, i, j) ] = true;
        
        return true;
    }

public:

    bool isValidSudoku(vector<vector<char>>& board)
    {
        for(int i = 1; i < 9; i+= 3)
            for(int j = 1; j < 9; j+=3)
                if(isValidBox(board, i, j) == false)
                    return false;
        
        for(int i = 0; i < 9; i++)
            if(isValidRow(board, i) == false)
                return false;
        
        for(int j = 0; j < 9; j++)
            if(isValidCol(board, j) == false)
                return false;

        return true;
    }
};
