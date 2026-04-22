class Solution {
public:


    double Distance(double x1, double y1){
        double ans = (x1*x1) + (y1*y1);
        return sqrt(ans);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
            int i,j;
            int n = points.size();
            double hold;
            int l,r;
            priority_queue<pair<double, vector<int>>, 
                       vector<pair<double, vector<int>>>, 
                       greater<pair<double, vector<int>>>> pq;
            for(i=0;i<n;i++){
                vector<int>temp = points[i];
                l = temp[0] , r = temp[1];
                hold = Distance(l,r);
                pq.push({hold,temp});
            }
            vector<vector<int>>ans;
            while(ans.size()!=k){
                l = pq.top().second[0], r = pq.top().second[1];
                vector<int>temp;
                temp.push_back(l); temp.push_back(r);
                ans.push_back(temp);
                pq.pop();
            }

            return ans;
    }
};
