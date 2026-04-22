class Solution {
public:

    int get_bit(int x , int pos){
    
    return (x >> pos) & 1;
    
}
    int getSum(int a, int b) {
        int sum=0;
        int i;
        int l,r,s,carry=0;
        for(i=0;i<32;i++){
            l = get_bit(a,i);
            r = get_bit(b,i);
           
            s = (l+r)%2+carry;
            sum+=((1<<i)*s);

             if((l+r)==2){
                carry = 1;
               
            }else{
                carry=0;
               
            }
        }
        return sum;
    }
};
