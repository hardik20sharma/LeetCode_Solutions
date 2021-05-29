class Solution {
public:
    bool checkOnesSegment(string s)
    {
        short i = 0;

        while(i < s.length())
            if (s[i] == '1')
                i++;
            else
                break;

        while(i < s.length())
            if (s[i] == '0')
                i++;
            else
                break;
        
        return i == s.length();
    }
};
