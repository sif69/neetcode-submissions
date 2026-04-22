class Solution {
public:
    string minWindow(string s, string t) {
        int i,j,n,m;

        n = s.size() , m = t.size();

        if(s.empty() || t.empty()) return "";

        vector<int> need(128, 0), have(128, 0);
        int required = 0;

        // Count frequencies of characters in t
        for (char c : t) {
            if (need[c] == 0) required++;
            need[c]++;
        } 

        int l=0,r=0,minlen = INT_MAX;
        int start,len,formed=0;
        char ch;
        for(r=0;r<n;r++){
             ch = s[r];
             have[ch]++;
             if(have[ch] == need[ch]) formed++; 

             while(required == formed){
                len = (r-l)+1;
                if(len < minlen){
                    minlen = len;
                    start = l;
                }

                ch  = s[l];
                have[s[l++]]--;
                if(have[ch] < need[ch]) formed--;
             }
        }

        return minlen == INT_MAX ? "" : s.substr(start, minlen);

    }
};
