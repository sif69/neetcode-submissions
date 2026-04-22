class Solution {
public:
    int singleNumber(vector<int>& nums) {
        

        int i,j;
        int ans=-1;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(i=0;i<n;i++){

            if(i==0){
                if(nums[i]!=nums[i+1]){
                    ans=nums[i];
                    break;
                }
            }else if(i==(n-1)){
                if(nums[i]!=nums[i-1]){
                    ans=nums[i];
                    break;
                }
            }else{
                 if(nums[i]!=nums[i-1]&&nums[i]!=nums[i+1]){
                    ans=nums[i];
                    break;
                 }
            }
        }
        return ans;
    }
};
