class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> cur(3, 0);

        for (auto &t : triplets) {
            if (t[0] > target[0] || 
                t[1] > target[1] || 
                t[2] > target[2]) continue;

            for (int i = 0; i < 3; i++) {
                cur[i] = max(cur[i], t[i]);
            }
        }

        return cur == target;
    }
};