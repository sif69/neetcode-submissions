class Solution {
public:
    vector<vector<int>> memo;

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        memo.resize(m+1,vector<int>(n+1,-1));
        return lcs(text1, text2, 0, 0);
    }

    int lcs(string& text1, string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int res = max(lcs(text1,text2,i+1,j),lcs(text1,text2,i,j+1));

        res = max(res,lcs(text1,text2,i+1,j+1) + (text1[i] == text2[j] ));
        return memo[i][j] = res;
    }
};