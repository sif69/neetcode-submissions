class Solution {
public:
    int Ans(int r , int l , string tokens){
        if(tokens == "+") return r+l;
        if(tokens == "-") return r-l;
        if(tokens == "*") return r*l;
        if(tokens == "/") return r/l;
    }
    int evalRPN(vector<string>& tokens) {
        
        int n = tokens.size();
        stack<int>st;
        int i;

        int l,r,ans;

        for(i=0;i<n;i++){
            if(tokens[i]=="+"
            ||tokens[i]=="*"
            ||tokens[i]=="-"
            ||tokens[i] =="/"){
                      l = st.top();
                      st.pop();
                      r = st.top();
                      st.pop();
                      ans = Ans(r,l,tokens[i]);
                      st.push(ans); 
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
