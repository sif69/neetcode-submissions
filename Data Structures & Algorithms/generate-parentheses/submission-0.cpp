class Solution {
public:

    void backtrack(int oN,int cN, int n,
    vector<string>&res , string& stck){
        if(oN == cN && oN == n){
            res.push_back(stck);
            return;
        }
        if(oN < n){
            stck+='(';
            backtrack(oN+1, cN , n , res, stck);
            stck.pop_back();
        }
         if(cN < oN){
            stck+=')';
            backtrack(oN, cN+1 , n , res, stck);
            stck.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        string stck;
        backtrack(0 , 0 , n , res, stck);
        return res;
    }
};
