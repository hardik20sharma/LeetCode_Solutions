class Solution {

    vector<vector<int>> dp;

    int sol(string &s1, string &s2, int i, int j)
    {   
        if(i < 0)           // Insert all the elements of s2 in s1
            return j + 1;

        if(j < 0)           // s2 is empty, make s1 empty
            return i + 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])  // When same, ignore
            return dp[i][j] = sol(s1, s2, i-1, j-1);

        return dp[i][j] = 1 + min(
                                    sol(s1, s2, i, j-1),          // Inserting a character
                                    
                                    min(  
                                          sol(s1, s2, i-1, j-1),  // Replacing a character
                                          sol(s1, s2, i-1, j)     // Deleting a character
                                       )
                                 );    
    }

public:
    int minDistance(string word1, string word2)
    {
        dp.clear();
        dp.resize(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return sol(word1, word2, word1.size() - 1, word2.size() - 1);
    }
};
