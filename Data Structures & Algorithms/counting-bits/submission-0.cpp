class Solution {
public:
    int ans(int k){
        int cnt = 0;
        while(k){
            cnt+=(k%2);
            k/=2;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> res;

        int i , total = 0;

        for(i=0;i<=n;i++){
           res.push_back(ans(i));
        }

        return res;

    }
};
