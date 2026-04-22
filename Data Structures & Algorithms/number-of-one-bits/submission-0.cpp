class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t i,ans=0;
            for(i=0;i<32;i++){
                    
                    ans+=((1<<i)&n)?1:0;
            }

            return ans;
    }
};
