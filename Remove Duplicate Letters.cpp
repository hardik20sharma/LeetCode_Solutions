class Solution {
public:
    string removeDuplicateLetters(string str)
    {
        string res;
        unordered_map<char, int> m;

        for(int i=0; i<str.length(); i++)
            m[str[i]]++;

        if(res.length() == m.size())
            return res;

        for(int i=0; i<str.length(); i++)
        {
            while(res.length() > 0 && res.back() > str[i] && m[res.back()] > 0 && res.find(str[i]) == -1)
                res.pop_back();
         
            if(res.find(str[i]) == -1)
                res.push_back(str[i]);
     
            m[str[i]]--;
        }    

        return res;
    }
};
