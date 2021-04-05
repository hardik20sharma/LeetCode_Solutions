class Solution {
public:
    
    vector<string> res;
    
    void gen(int n, int open_brackets = 0, int close_brackets = 0, string output="")
    {
        if(open_brackets == n && close_brackets == n)
        {
            res.push_back(output);
            return;
        }

        if(open_brackets < n)
            gen(n, open_brackets + 1, close_brackets, output + '(');
        
        if(close_brackets < open_brackets)
            gen(n, open_brackets, close_brackets + 1, output + ')');
    }

    vector<string> generateParenthesis(int n)
    {
        res.clear();
        gen(n);
        return res;
    }
};
