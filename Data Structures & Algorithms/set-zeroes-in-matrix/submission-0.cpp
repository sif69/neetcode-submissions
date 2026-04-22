class Solution {
public:



    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int>rows,cols;
        int i,j;
        int n,m;
        n = matrix.size() , m = matrix[0].size();

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(!matrix[i][j]){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
         for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(rows[i] || cols[j]){
                    matrix[i][j] = 0;
                }
            }
        }


       





    }
};
