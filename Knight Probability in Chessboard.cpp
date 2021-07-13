class Solution
{
    // 8 possibilites for the knight to move.
    int dir[8][2] = { {-2, -1}, {-1, -2}, {2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {2, 1}, {1, 2} };
    
    unordered_map<string, double> dp;   // DP, we are using memoization
    
    // Generates the key for the DP. We are using string.
    string key_gen(int k, int r, int c) {
        return to_string(k) + " " + to_string(r) + " " + to_string(c);
    }
    
    // Checks if knight is in grid or not
    bool inGrid(int r, int c, int n) {
        if(r < 0 || n <=r || c < 0 || n <= c)
            return false;
        return true;
    }
    
    // Actual solution
    double sol(int n, int k, int r, int c) {
        
        string key = key_gen(k, r, c);  // Generating the key for DP
        
        if(dp[key])         // If result is already present in DP, return it
            return dp[key];
        
        if(inGrid(r, c, n) == false)    // If knight is outside grid, we return 0
            return 0;
        
        if(k == 0)      // When knight has no moves, it has only one possibility. To stay in that particular place.
            return 1;

        double probability = 0.0;   // Initializing the variable possibility.
        
        // Checking each and every possibility for knight from current position. We are dividing by 8 because knight can go to 8 difference blocks from current one.
        for(int i = 0; i < 8; i++)
            probability += sol(n, k-1, r + dir[i][0], c + dir[i][1]) / 8.0;
        
        // Returning the possibility and storing it in DP too.
        return dp[key] = probability;
    }

public:

    double knightProbability(int n, int k, int row, int column) {
        dp.clear();                             // Clearing the dp
        double result = sol(n, k, row, column); // Solving the problem
        return result;
    }
};
