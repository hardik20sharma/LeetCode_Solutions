class Solution {
public:
    int titleToNumber(string colTitle)
    {
        int sum = 0;

        for(int i = 0; i < colTitle.size(); i++)
            sum = (sum * 26) + (colTitle[i] - 'A' + 1);

        return sum;
    }
};
