class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& w) {

        map <char, vector <string> > hash_map;

        for(string s : w)
            hash_map[s[0]].push_back(s);

        int ans = 0;

        for(int i = 0; i < s.size(); i++)
        {
            char x = s[i];

            if(hash_map.find(x) != hash_map.end())
            {
                vector <string> temp = hash_map[x];
                hash_map.erase(x);

                for(string t : temp)

                    if(t.size() == 1)
                        ans++;
                    else
                        hash_map[t[1]].push_back(t.substr(1));
            }
        }

        return ans;
    }
};
