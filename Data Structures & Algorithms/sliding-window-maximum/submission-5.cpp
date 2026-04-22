class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int i,j;
        int n = nums.size();
        vector<int>ans;

        priority_queue<int> pq;
        map<int,int>mp;
        int l = 0;
        for(i=0;i<k;i++){
             pq.push(nums[i]);
             mp[nums[i]]++;
        }

        ans.push_back(pq.top());
        mp[nums[l]]--;
        l++;

            int p;

        for(i=0;i<(n-k);i++){
            p = (i+k);
            pq.push(nums[p]);
            mp[nums[p]]++;
            
                if(mp[pq.top()]) {
                    ans.push_back(pq.top());
                   
                }else{
                    while(!mp[pq.top()]){
                        
                        pq.pop();
                    }
                    ans.push_back(pq.top());
                }
                mp[nums[l]]--;
                l++;
        }

        return ans;

    }
};
