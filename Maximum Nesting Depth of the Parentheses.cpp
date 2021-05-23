class Solution {
public:
    int maxDepth(string s) {

        int open_brackets = 0, res = 0;
        
        for(char c : s)
        {
            if(c == '(')
                open_brackets++;
            else if(c == ')')
                open_brackets--;
            
            res = max(res, open_brackets);
        }
        
        return res;
    }
};
