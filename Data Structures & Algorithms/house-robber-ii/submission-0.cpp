class Solution {
public:
    // Standard House Robber I on a subarray [start, end]
    int robRange(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case: only one house
        if (n == 1) return nums[0];

        // Case 1: include first house  → exclude last  [0, n-2]
        // Case 2: exclude first house  → include last  [1, n-1]
        return max(robRange(nums, 0, n - 2),
                   robRange(nums, 1, n - 1));
    }
};