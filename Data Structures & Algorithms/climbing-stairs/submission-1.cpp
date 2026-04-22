class Solution {
public:
    
    int tot = 0;
    int CS(int n , int cnt, vector<int>&dp){
        if(cnt>=n) return cnt==n;
        if(dp[cnt]!=-1) return dp[cnt];
        return CS(n,cnt+1,dp)+CS(n,cnt+2,dp);
    }
    int climbStairs(int n) {
          
            vector<int>dp(n,-1);
            return CS(n,0,dp);
          
    }
};
