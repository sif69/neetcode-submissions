class Solution {
public:
    
    int tot = 0;
    void CS(int n , int cnt){
        if(cnt>n) return;
        if(cnt == n){
            tot++;
            return;
        }
        CS(n,cnt+1);
        CS(n,cnt+2);
    }
    int climbStairs(int n) {
          

            CS(n,0);
          return tot;
    }
};
