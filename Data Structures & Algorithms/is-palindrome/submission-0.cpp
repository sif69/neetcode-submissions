class Solution {
public:
    bool isPalindrome(string s) {
        int i,n=s.size();
        char ch;
        string temp;
        for(i=0;i<n;i++){
           if(s[i]>='A'&&s[i]<='Z' ||
           s[i]>='a'&&s[i]<='z' || s[i]>='0'&&s[i]<='9'){
            ch = towlower(s[i]);
            temp.push_back(ch);  
           }
        }

        bool ans = true;
        n = temp.size();
        for(i=0;i*2<n;i++){
            if(temp[i]!=temp[n-i-1]){
                ans=false;
                break;
            }
        }
        return ans;
    }
};
