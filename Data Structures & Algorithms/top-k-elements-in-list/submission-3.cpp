class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
       
       
          unordered_map<int,int>mp;

            for(auto it:nums){
             mp[it]++;
          }

          vector<pair<int, int>> vec(mp.begin(), mp.end());
        
   
    sort(vec.begin(), vec.end(),
     [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second; 
    });
    int cnt = 0;
    vector<int>ans;
    
    for(auto it:vec){
        if(cnt==k) break;
        ans.push_back(it.first);
        cnt++;
    }

    return ans;

    }
   
};
