class Solution {
public:
    string customSortString(string order, string str)
    {
        vector<int> count(26, 0);

        for (char c : str)
            count[c - 'a']++;

        int i = 0;

        for (char c : order)
            while (count[c - 'a'])
            {
                str[i++] = c;
                count[c - 'a']--;
            }

        for (char c = 'a'; c <= 'z'; c++)
            while (count[c - 'a'])
            {
                str[i++] = c;
                count[c - 'a']--;
            }

        return str;
    }
};
