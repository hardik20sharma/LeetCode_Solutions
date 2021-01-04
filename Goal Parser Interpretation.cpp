class Solution {
public:
    string interpret(string s)
    {
        string res;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == 'G')
                res += 'G';
            else if(s.substr(i, 2) == "()")
            {
                res += 'o';
                i++;
            }
            else if(s.substr(i, 4) == "(al)")
            {
                res += "al";
                i += 3;
            }
        }
        
        return res;
    }
};
