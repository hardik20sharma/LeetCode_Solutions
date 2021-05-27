class Solution {
public:
    string freqAlphabets(string s)
    {
        string res;
        
        for(int i = s.length() - 1; 0 <= i; i--)

            if('1' <= s[i] && s[i] <= '9')
                res += (s[i] - '1') + 'a';

            else if(s[i] == '#')
            {
                res += ( (s[i-2] - '0') * 10 + (s[i-1] - '0') - 1) + 'a';
                i -= 2;
            }

        return string(res.rbegin(), res.rend());
    }
};
