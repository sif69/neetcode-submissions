class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i,j;
        uint32_t ans=0;
        int bit;
        for(i=0;i<32;i++){
            bit = (n >> i) & 1;
            ans|=(bit << (31-i));
        }
        return ans;
        
    }
};
