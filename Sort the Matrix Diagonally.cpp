class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {       
        int m = mat.size(), n = mat[0].size();

        for(int j=0; j<n; j++)
        {
            vector<int> temp;         
            int i = 0, j_temp = j;

            while(i < m && j_temp < n)
                temp.push_back(mat[i++][j_temp++]);

            sort(temp.begin(), temp.end());

            for(i = 0, j_temp = j; i<m && j_temp<n; i++, j_temp++)
                mat[i][j_temp] = temp[i];
        }

        for(int i=1; i<m; i++)
        {
            vector<int> temp;         
            int i_temp = i, j = 0;

            while(i_temp < m && j < n)
                temp.push_back(mat[i_temp++][j++]);

            sort(temp.begin(), temp.end());

            for(i_temp = i, j = 0; i_temp<m && j<n; i_temp++, j++)
                mat[i_temp][j] = temp[j];
        }

        return mat;
    }
};
