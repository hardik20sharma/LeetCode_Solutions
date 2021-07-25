class Solution {
    
    bool sol(vector<int> &arr, int start, vector<bool> &visited)
    {
        if(start < 0 || arr.size() <= start || visited[start] == true)
            return false;

        if(arr[start] == 0)
            return true;

        visited[start] = true;

        return sol(arr, start - arr[start], visited) || sol(arr, start + arr[start], visited);
    }

public:
    bool canReach(vector<int>& arr, int start)
    {
        vector<bool> visited(arr.size(), false);
        return sol(arr, start, visited);
    }
};
