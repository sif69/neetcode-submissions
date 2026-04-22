class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i,j;
        int n = prices.size();
        int mx =0,mn=1e5;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                mx=max(mx,prices[j]-prices[i]);
            }
        }
        return mx;
        

       
        
    }
};
