class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int l = newInterval[0], r = newInterval[1];
        int n = intervals.size();
        int i = 0;

        // Zone 1: intervals that end before newInterval starts → keep
        while (i < n && intervals[i][1] < l) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Zone 2: intervals that overlap newInterval → merge
        while (i < n && intervals[i][0] <= r) {
            l = min(l, intervals[i][0]);   // expand left if needed
            r = max(r, intervals[i][1]);   // expand right if needed
            i++;
        }
        ans.push_back({l, r});             // push merged interval

        // Zone 3: intervals that start after newInterval ends → keep
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};