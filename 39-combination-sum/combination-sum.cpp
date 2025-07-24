class Solution {
public:
        void backtrack(int index, vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (target < 0 || index == candidates.size()) return;

        // include current
        path.push_back(candidates[index]);
        backtrack(index, candidates, target - candidates[index], path, result);
        path.pop_back();

        // skip current
        backtrack(index + 1, candidates, target, path, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(0, candidates, target, path, result);
        return result;
    }
};