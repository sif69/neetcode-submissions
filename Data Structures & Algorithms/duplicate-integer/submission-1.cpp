class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>st;
        int n = nums.size();
        int i,j;
        for(i=0;i<n;i++){
            st.insert(nums[i]);
        }
        return st.size() != n;
    }
};