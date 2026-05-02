class Solution {
public:
    int robMin(vector<int>& nums, int ind, vector<int>& dp) {
        if (ind >= nums.size()) return 0;

        if (dp[ind] != -1) return dp[ind];

        int take = nums[ind] + robMin(nums, ind + 2, dp);
        int skip = robMin(nums, ind + 1, dp);

        return dp[ind] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robMin(nums, 0, dp);
    }
};