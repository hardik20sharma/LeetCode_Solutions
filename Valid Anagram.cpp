class Solution {
public:
    bool isAnagram(string s, string t)
    {
        vector<int> cnt(256, 0);

        for(int i=0; i<s.length(); i++)
            cnt[s[i] - 'a']++;
        
        for(int i=0; i<t.length(); i++)
            cnt[t[i] - 'a']--;

        for(int i=0; i<256; i++)
            if(cnt[i])
                return false;

        return true;
    }
};
