class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        if(s.length() == 0 || s.length() == 1)
            return false;
        else if(s.length() == 2 && s[0] == s[1])
            return true;
        
        int n = s.length();

        vector<int> factors;
        for(int i=1; i<n; i++)
            if(n % i == 0)
                factors.push_back(i);
        
        for(int i=0; i<factors.size(); i++)
        {
            string temp(s.begin(), s.begin() + factors[i]);
            string store;
            
            for(int k=1; k<=(n/factors[i]); k++)
                store += temp;
            
            if(store == s)
                return true;
        }
        return false;
    }
};
