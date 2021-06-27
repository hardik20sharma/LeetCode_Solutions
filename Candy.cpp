class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int sum = 0, n = ratings.size();
        
        vector<int> a (n, 1);

        for(int i = 0; i < n - 1; i++)
            if(ratings[i+1] > ratings[i])
                a[i+1] = a[i] + 1;

        for(int i = n - 1; i > 0; i--)
            if(ratings[i-1] > ratings[i] && a[i-1] < (a[i] + 1))
                a[i-1] = a[i] + 1;

        for(int i = 0; i < a.size(); i++)
            sum += a[i];

        return sum;
    }
};
