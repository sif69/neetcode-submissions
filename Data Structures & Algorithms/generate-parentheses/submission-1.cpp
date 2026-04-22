class Solution {
public:

    vector<string> res;
    
    void getPar(string s, int op, int cl , int n){

        if(op == n && cl == n){
            res.push_back(s);
            return;
        }
        if(op<n) getPar(s+'(',op+1,cl,n);
        if(op>cl) getPar(s+')',op,cl+1,n);
    }

    vector<string> generateParenthesis(int n) {
        
        getPar("",0,0,n);
        return res;

    }
};
