class Solution {
public:


    int check(vector<int>& piles , int mid){
        int i,j,res=0;

        for(i=0;i<piles.size();i++){
            res+=((piles[i]+mid-1)/mid);
        }
        return res;
    }
    int binarySearch(vector<int>& piles, int h){


        sort(piles.begin(),piles.end());

        int l = 1, r = piles[piles.size()-1],mid;

        while(l<=r){
            mid  = (l)+(r-l)/2;
            if(check(piles,mid)<=h){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ans = binarySearch(piles,h);

        return ans;


    }
};
