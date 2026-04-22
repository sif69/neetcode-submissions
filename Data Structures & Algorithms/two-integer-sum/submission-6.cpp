class Solution {
public:
   

    vector<int> twoSum(vector<int>& nums, int target) {
           int i,j = nums.size();
           int l,r;
           
           map<int,int>mp;
           for(i=0;i<j;i++) {
            mp[nums[i]] = i;
           }

           for(i=0; i < j; i ++){
              l= target - nums[i];
              if(mp.count(l)&&mp[l] !=i){

                return {i , mp[l]};
              }
              
           }
         return {};
    }
};
