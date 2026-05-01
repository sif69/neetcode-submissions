class Solution {
public:
    int jump(vector<int>& nums) {
         int i , l  ,  r , cnt = 0;

         l = 0 , r = 0;

         int n = nums.size();

         i = 0 ;

         int far  ;

         while( r < (n-1)){

                far = 0;

              for(i = l ; i <= r; i++){
                    far = max(far,i+nums[i]);
              }
              l = r + 1;
              r = far ;
              cnt++;
         }

         return cnt;
    }
};