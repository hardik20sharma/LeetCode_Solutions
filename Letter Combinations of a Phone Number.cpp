class Solution {
    vector<string> res;
    vector<string> digits_to_letters {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    
    void sol(string &digits, string output = "", int i = 0)
    {
        if(i == digits.size())
        {
            res.push_back(output);
            return;
        }
        
        for(char c : digits_to_letters[ digits[i] - '1' ])
            sol(digits, output + c, i + 1);
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits == "")
            return vector<string>();
        
        sol(digits);
        return res;
    }
};
