class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int i ,sum=0;
        priority_queue<int>pq;
        for(auto it:stones){
            pq.push(it);
        }
        int t1,t2;
        while(pq.size()>1){

            t1 = pq.top();
            pq.pop();
            t2 = pq.top();
            pq.pop();

            pq.push(t1-t2);


        }
        return pq.top(); 
    }
};
