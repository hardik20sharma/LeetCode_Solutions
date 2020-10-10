// Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3490/

bool cmp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

class Solution
{
public:
    
    int findMinArrowShots(vector< vector<int> > &points)
    {
        if(points.size() == 0)
            return 0;

        sort(points.begin(), points.end(), cmp);

        int curr_end = points[0][1], cnt = 1;

        for(int i = 1; i < points.size(); i++)
            if(curr_end < points[i][0])
            {
                cnt++;
                curr_end = points[i][1];
            }

        return cnt;
    }
};
