class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
       set<int>st;
       if (nums.empty()) return 0;
        int i,j;
        int n = nums.size();
        
        for(i=0;i<n;i++){
            st.insert(nums[i]);
        }
       vector<int> temp(st.begin(), st.end());
       
        int cnt=1;
        int mx=0;
        for(i=1;i<temp.size();i++){
            if((temp[i]-1) == temp[i-1]) {
                cnt++;
            }
            else {
                mx=max(mx,cnt);
                cnt=1;
            }
        }
        mx=max(mx,cnt);
        return mx;
       
    }
};
