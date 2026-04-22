class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int i,j;
            int n = nums.size(),mul = 1;
            vector<int>ans(n),temp;
            int flag=0;
            for(i=0;i<n;i++) {
                if(nums[i]){
                mul*=nums[i];
                }else{
                    flag=1;
                    temp.push_back(i);
                }
            }
            if(!flag){
                for(i=0;i<n;i++){
                    ans[i] =mul/nums[i];
                    
                }
            }else{
                if(temp.size()==1){
                for(i=0;i<temp.size();i++){
                    ans[temp[i]] = mul;
                }
                }
            }
           

            return ans;
    }
};
