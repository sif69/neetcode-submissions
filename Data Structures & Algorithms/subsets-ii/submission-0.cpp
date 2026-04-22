class Solution {
public:

    vector<vector<int>> res;
    vector<int> temp;
    map<vector<int>,int> mp;

    void solution(vector<int>&nums,vector<int>&curr, int x){
        
        
        if(x>=nums.size()) {
            temp = curr;
            sort(temp.begin(),temp.end());
            if(mp[temp]) return ;
            res.push_back(curr);
            mp[temp]++;
            return;
        }

         curr.push_back(nums[x]);   
         solution(nums,curr,x+1);
         curr.pop_back();
         solution(nums,curr,x+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        solution(nums, curr , 0);
        return res;
    }
    

    
   


};
