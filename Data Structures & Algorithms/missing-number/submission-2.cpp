class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int i;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(i=0;i<=n;i++){
            if(i!=nums[i]) return i;
        }
    }
};
