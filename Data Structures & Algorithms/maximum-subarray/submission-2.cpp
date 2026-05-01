class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int i ;
            int CurSum = nums[0] , MaxSum = nums[0];

            for(i = 1; i < nums.size() ; i ++ ){

                CurSum = max(nums[i],nums[i]+CurSum);

                MaxSum = max(CurSum, MaxSum);
            }

            return MaxSum;
            
    }
};
