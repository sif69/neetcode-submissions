class Solution {
public:
    vector<vector<int>> dp;
    int sum = 0;

    int findTargetSumWays(vector<int>& nums, int target) {
        for (int x : nums) sum += x;

        dp.resize(nums.size(), vector<int>(2 * sum + 1, -1));

        return backtrack(0, 0, nums, target);
    }

    int backtrack(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return total == target;
        }

        if (dp[i][total + sum] != -1)
            return dp[i][total + sum];

        int add = backtrack(i + 1, total + nums[i], nums, target);
        int sub = backtrack(i + 1, total - nums[i], nums, target);

        return dp[i][total + sum] = add + sub;
    }
};