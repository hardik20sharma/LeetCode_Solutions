class Solution {
public:
    bool buddyStrings(string a, string b)
    {
        if(a.size() != b.size())
            return false;

        if(a == b)
        {
            set<char> s;
            for(int i=0; i<a.size(); i++)
                if(s.find(a[i]) == s.end())
                    s.insert(a[i]);
                else    
                    return true;
            return false;
        }

        else
        {
            int diff_cnt = 0;
            for(int i=0; i<a.size(); i++)
                if(a[i] != b[i])
                    diff_cnt++;

            if(diff_cnt != 2)
                return false;

            char c1, c2;
            bool found = false;
            for(int i=0; i<a.size(); i++)
                if(a[i] != b[i] && !found)
                {
                    c1 = a[i]; c2 = b[i];
                    found = true;
                }
                else if(a[i] != b[i] && found)
                    if(c2 != a[i] || c1 != b[i])
                        return false;

            return true;
        }
    }
};
