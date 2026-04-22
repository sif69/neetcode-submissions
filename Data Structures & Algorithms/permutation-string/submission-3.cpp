class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int i,j;

      
        

        int n = s1.size() , m = s2.size() ;
         
        if(s1 == s2) return true;
        if (n>m) return false;

        sort(s1.begin(),s1.end());
        string temp;

        bool ok = false;

        for(i=0;i<(m-n+1);i++){
            temp = s2.substr(i,n);
            sort(temp.begin(),temp.end());
            if(temp == s1){
                ok = true;
                break;
            }
        }

        return ok;
    }
};
