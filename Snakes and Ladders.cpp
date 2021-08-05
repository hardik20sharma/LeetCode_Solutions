class Solution {
    
    pair<int, int> coordinate(int curr, int board_size)
    {
        int row = (board_size - 1) - ( (curr - 1) / board_size );
        int col = (curr - 1) % board_size;

        if(row % 2 == board_size % 2)
            return { row, board_size - 1 - col };

        else
            return { row, col };
    }

public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size(), res = 0;

        vector<vector<bool>> visited (n, vector<bool>(n, false));
        queue<int> q;

        q.push(1);
        visited[n-1][0] = true;

        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();

                if(curr == n*n)
                    return res;

                for(int possible_step = 1; possible_step <= 6; possible_step++)
                {
                    if( n*n < curr + possible_step )
                        break;
                    
                    pair<int, int> next = coordinate(curr + possible_step, n);
                    
                    int row = next.first, col = next.second;

                    if (visited[row][col])
                        continue;

                    visited[row][col] = true;

                    (board[row][col] == -1) ? q.push(curr + possible_step) : q.push(board[row][col]);
                }
            }

            res++;
        }

        return -1;
    }
};
