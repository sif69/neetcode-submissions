class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
          vector<int> cur ;
          backtrack(nums , target , cur , 0);
          return res;

    }

    void backtrack(vector<int>& nums, int target, vector<int>& cur , int x){
            if (target == 0){
                res.push_back(cur);
                return ;
            }
            if(target < 0 || x >= nums.size()){
                return ;
            }

            cur.push_back(nums[x]);
            backtrack(nums, target - nums[x], cur , x);
            cur.pop_back();
            backtrack(nums , target , cur , x+1);



    }
};
