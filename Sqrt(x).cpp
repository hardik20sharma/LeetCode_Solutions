class Solution {
public:
    int mySqrt(int x)
    {
        long long int num = 1;
        
        while( num * num <= x)
            num++;
        
        return (int) num-1;
    }
};
