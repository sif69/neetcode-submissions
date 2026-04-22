class Solution {
public:
    int findMin(vector<int> &nums) {
        int i ;
        int mx = INT_MAX;
        for(i=0;i<nums.size();i++){
            if(nums[i] < mx){
                mx = nums[i];
            }
        }
        return mx;
    }
};
