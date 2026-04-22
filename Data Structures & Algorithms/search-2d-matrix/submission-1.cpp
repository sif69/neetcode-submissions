class Solution {
public:

   

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int i,j;
        int n = matrix.size() , m = matrix[0].size();

        int l = 0 , r = m-1 , mid , x;
        for(i=0;i<n;i++){

            l = 0 , r = m-1 ;
            mid = (l)+(r-l)/2;
            while(l <= r){
                 mid = (l)+(r-l)/2;
                 x = matrix[i][mid];
                 if( x == target){
                    return true;
                 }else if( x > target){
                    r = mid - 1;
                 }else{
                    l = mid + 1;
                 }


            }

        }
        return false;
    }
};
