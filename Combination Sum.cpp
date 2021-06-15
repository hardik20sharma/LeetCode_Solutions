class Solution {
public:

    set<vector<int>> res;

    void sol(vector<int> &a, int &target, int sum, vector<int> combination, int curr)
    {   
        if(curr == -1 || target < sum)
            return;

        if(sum == target)
        {
            res.insert(combination);
            return;
        }

        sol(a, target, sum, combination, curr - 1);

        combination.push_back(a[curr]);

        sol(a, target, sum + a[curr], combination, curr);
        sol(a, target, sum + a[curr], combination, curr - 1);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sol(candidates, target, 0, vector<int>(), candidates.size() - 1);
        return vector(res.begin(), res.end());
    }
};
