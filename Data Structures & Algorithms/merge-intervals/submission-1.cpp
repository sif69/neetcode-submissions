class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i;

        int l , r ;
        vector<vector<int>>  ans;
        sort(intervals.begin() , intervals.end());
        
        l = intervals[0][0] , r = intervals[0][1] ;

        for(i =  1 ; i < intervals.size(); ){

             if(i>=(intervals.size())) break;
              if(intervals[i][0]<=r){
                    while( i < intervals.size() && intervals[i][0] <=r){
                        l = min(l,intervals[i][0]) ;
                        r = max(r,intervals[i][1]);
                        i++;
                        
                    }
              }else{
                 ans.push_back({l,r});
                 l = intervals[i][0] , r = intervals[i][1] ;
                 i++;
              }
        }
        ans.push_back({l,r});
        return ans;
    }
};
