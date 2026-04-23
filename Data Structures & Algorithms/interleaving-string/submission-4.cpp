class Solution {
public:
    unordered_map<int, bool> memo;

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        return dfs(0, 0, 0, s1, s2, s3);
    }

    bool dfs(int i, int j, int k, string& s1, string& s2, string& s3) {
        if (k == s3.size()) return i == s1.size() && j == s2.size();

        int key = i * 201 + j;          // unique key for (i,j) pair
        if (memo.count(key)) return memo[key];

        bool res = false;
        if (i < s1.size() && s1[i] == s3[k])
            res = dfs(i + 1, j, k + 1, s1, s2, s3);
        if (!res && j < s2.size() && s2[j] == s3[k])
            res = dfs(i, j + 1, k + 1, s1, s2, s3);

        return memo[key] = res;
    }
};