class Solution {
public:
    
   
    string encode(vector<string>& strs) {
              string temp = "";

              for(auto it:strs){
                 temp+=it;
                 temp+='?';
              }
              return temp;
    }

    vector<string> decode(string s) {
            vector<string>ans;
            string curr;
            int i=0,n=s.size();
            for(i=0;i<n;i++){
                if(s[i]!='?'){
                    curr.push_back(s[i]);
                }else{
                    ans.push_back(curr);
                    curr.clear();
                }
            }
          
           

            return ans;
    }
};
