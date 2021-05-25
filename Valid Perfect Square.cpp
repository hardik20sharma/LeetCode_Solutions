class Solution {
public:
    bool isPerfectSquare(int num)
    {
        long long int n = 1;
        
        for( ; n * n < num; n++);

        return (n * n == num);
    }
};
