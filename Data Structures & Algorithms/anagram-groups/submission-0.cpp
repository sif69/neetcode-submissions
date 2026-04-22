class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int cnt = 0;

        map<string,int>mp;
         
        vector<vector<string>>ans;

        int n = strs.size();

        int i;
        string temp;

       for (int i = 0; i < n; i++) {
            string sorted_str = strs[i];
            sort(sorted_str.begin(), sorted_str.end());

            if (mp.count(sorted_str) == 0) {
                mp[sorted_str] = cnt++;
                ans.push_back({strs[i]}); 
            } else {
                ans[mp[sorted_str]].push_back(strs[i]); 
            }
        }
     
        return ans;

    }
};
