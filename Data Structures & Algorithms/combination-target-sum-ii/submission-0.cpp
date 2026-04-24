class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int start, int target, vector<int>& ds) {

        // Base case 1: found valid combination
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Early termination: sorted array, no point going further
            if (candidates[i] > target) break;

            // Skip duplicates at the SAME recursion level
            // i > start means: we're not at first pick of this level
            // candidates[i] == candidates[i-1] means: duplicate
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            ds.push_back(candidates[i]);
            solve(candidates, i + 1, target - candidates[i], ds); // i+1: no reuse
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        solve(candidates, 0, target, ds);
        return ans;
    }
};