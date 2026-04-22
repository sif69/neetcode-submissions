class Solution {
public:

    int dig(int x){
        int sum = 0, l ;
        while(x){
            l=x%10;
            sum+=(l*l);
            x/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        
       unordered_map<int,int>mp;
       mp[n]++;
       int l=n;
       while(1){
            l = dig(l);
             if(l == 1) return true;
             else if(mp[l]) return false;
            mp[l]++;
       }
    }
};
