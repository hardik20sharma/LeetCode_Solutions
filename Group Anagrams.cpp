class Solution {

    string anagram(string s)
    {
        vector<int> letter(26, 0);

        for(char c : s)
            letter[c-'a']++;

        string res;

        for(int i = 0; i < 26; i++)
            for(int j = 0; j < letter[i]; j++)
                res += ('a' + i);

        return res;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& str)
    {
        vector<vector<string>> res;

        map<string, vector<string>> m;

        for(string s : str)
            m[anagram(s)].push_back(s);

        for(pair<string, vector<string>> p : m)
            res.push_back(p.second);

        return res;
    }
};
