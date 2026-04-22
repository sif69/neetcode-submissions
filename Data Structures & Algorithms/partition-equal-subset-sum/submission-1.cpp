class Solution {
public:
    int dp[55][10005];

    bool func(int ind, int sum, vector<int>& nums) {
        if (sum == 0) return true;
        if (ind < 0) return false;

        if (dp[ind][sum] != -1) return dp[ind][sum];

        bool isPossible = func(ind - 1, sum, nums);

        if (nums[ind] <= sum) {
            isPossible |= func(ind - 1, sum - nums[ind], nums);
        }

        return dp[ind][sum] = isPossible;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % 2) return false;
        sum /= 2;

        // manual initialization
        for (int i = 0; i < 55; i++) {
            for (int j = 0; j < 10005; j++) {
                dp[i][j] = -1;
            }
        }

        return func(nums.size() - 1, sum, nums);
    }
};