class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        short cnt = 0;
        for(; n; n/=2)
            if(n & 1)
                cnt++;
        return cnt;
    }
};
