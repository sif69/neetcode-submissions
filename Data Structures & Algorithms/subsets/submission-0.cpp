class Solution {
public:
    vector<vector<int>> res;

    void solution(vector<int>&nums,vector<int>&curr, int x){
        
        
        if(x>=nums.size()) {
            res.push_back(curr);
            return;
        }

         curr.push_back(nums[x]);   
         solution(nums,curr,x+1);
         curr.pop_back();
         solution(nums,curr,x+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        solution(nums, curr , 0);
        return res;
    }
};
