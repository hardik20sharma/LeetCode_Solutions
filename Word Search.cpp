class Solution {

    int X[4] = {-1, 1, 0, 0};
    int Y[4] = { 0, 0,-1, 1};

    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int index = 0)
    {
        if(board[i][j] != word[index])
            return false;

        if(index + 1 == word.size())
            return true;

        char c = board[i][j];
        board[i][j] = '*';

        bool success = false;

        for(int move = 0; move < 4; move++)
        {
            int x = i + X[move];
            int y = j + Y[move];

            if( 0 <= x && 0 <= y && x < board.size() && y < board[0].size() )
                if(index + 1 < word.size() && board[x][y] != '*')
                    success = (success || dfs(board, word, x, y, index + 1));

            if(success)
            {
                board[i][j] = c;
                return true;
            }
        }

	    board[i][j] = c;
	    return false;
    }

public:

    bool exist(vector<vector<char>>& board, string word)
    {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0])   
                    if( dfs(board, word, i, j) == true )
                        return true;

        return false;
    }
};
