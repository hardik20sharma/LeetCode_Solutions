class Solution {
public:
    int balancedStringSplit(string s) {
        
        int res = 0, cnt = 0;
        for(char c : s)
        {
            (c == 'L') ? cnt++ : cnt--;

            if(cnt == 0)
                res++;
        }
        
        return res;
    }
};
