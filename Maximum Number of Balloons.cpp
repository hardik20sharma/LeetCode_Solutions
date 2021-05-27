class Solution {
public:
    int maxNumberOfBalloons(string s)
    {
        vector<int> l(26, 0);

        for(char c : s)
            l[ c - 'a' ]++;

        return min( l[0], min(l[1], min( l[11] / 2, min(l[13], l[14] / 2) ) ) );
    }
};
