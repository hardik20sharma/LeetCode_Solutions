class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if(matrix.size() == 0)
            return false;

        int i;
        for(i=0; i<matrix.size(); i++)
            if(matrix[i].size() == 0 || (i==0 && target < matrix[i][0]) )
                return false;
            else if(matrix[i][0] == target)
                return true;
            else if(target < matrix[i][0])
                break;
        i--;

        if( find(matrix[i].begin(), matrix[i].end(), target) == matrix[i].end() )
            return false;
        else
            return true;

        return false;
    }
};
