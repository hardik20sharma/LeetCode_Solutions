class Solution {
public:
    int lengthOfLastWord(string s)
    {
        while(!s.empty() && s[s.length() - 1] == ' ')
            s.pop_back();
        
        if(s == "")
            return 0;
        
        int res = 1;
        
        for(int i=s.length() - 1; 0 < i && (i == 0 || s[i-1] != ' '); i--, res++);
        
        return res;
    }
};
