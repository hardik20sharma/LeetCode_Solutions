class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;

        for(int i=0; i<s.length(); i++)
        {
            vector<bool> cnt(256);
            for(int j=i; j<s.length(); j++)
            {
                if(cnt[s[j]])
                    break;
                result = max(result, j-i+1);
                cnt[s[j]] = true;
            }
        }

        return result;
    }
};
