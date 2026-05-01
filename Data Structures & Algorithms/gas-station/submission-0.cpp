class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int gsum = 0 , csum = 0;
        int i, n = gas.size();
        for(i=0;i<n;i++) gsum+=gas[i];
        for(i=0;i<n;i++) csum+=cost[i];
        if(gsum < csum) return -1;

        int in = 0 , temp = 0;
        for(i=0;i<n;i++){
            temp +=(gas[i]-cost[i]);
            if(temp < 0){
                in = i + 1;
                temp = 0;
            }
        }
        return in;
    }
};
