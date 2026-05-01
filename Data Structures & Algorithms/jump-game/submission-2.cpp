class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i , mxsum = 0;

        for(i=0;i<nums.size();i++){

            if( i > mxsum ) return false;
            mxsum = max(mxsum,i+nums[i]);
            
        }
        return true;
    }
};
