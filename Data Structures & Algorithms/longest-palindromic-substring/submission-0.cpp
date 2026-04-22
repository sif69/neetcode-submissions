class Solution {
public:
     vector<string>res;

    string longestPalindrome(string s) {
        
       

        for(int i=0;i<s.size();i++){
            countPal(i,i,s);
            countPal(i,i+1,s);
        }
        string temp = "s";
        for(auto it:res){
            if(it.size() >= temp.size()){
                temp = it;
            }
        }
        return temp;
    }

    void countPal(int l , int r , string s){
        string ans;

        while(l>=0&&r<s.size()&& s[l] == s[r]){

            ans = s.substr(l,(r-l+1));
            res.push_back(ans);
            l--;
            r++;
        }
        
    }
};
