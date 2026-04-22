class Solution {
public:
    double myPow(double x, int n) {
        double l = x;
        int i;
       if(n == 0) return 1.00;
       for(i=1;i<abs(n);i++) x = x*l;
       if(n<0) x = (1/x);
       
        return x;
    }
};
