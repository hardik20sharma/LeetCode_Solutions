class Solution {
public:
    int romanToInt(string s)
    {
        map<char, int> m;
        m.insert( pair<char, int> {'I', 1} );
        m.insert( pair<char, int> {'V', 5} );
        m.insert( pair<char, int> {'X', 10} );
        m.insert( pair<char, int> {'L', 50} );
        m.insert( pair<char, int> {'C', 100} );
        m.insert( pair<char, int> {'D', 500} );
        m.insert( pair<char, int> {'M', 1000} );
        
        int result = 0;
        
        for(int i=0; i<s.length(); i++)
            (m[s[i]] >= m[s[i+1]]) ? result += m[s[i]] : result -= m[s[i]];
        
        return result;
    }
};
