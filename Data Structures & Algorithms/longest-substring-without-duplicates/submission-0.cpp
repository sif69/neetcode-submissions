class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int mx = 0;

        int left = 0;  // this replaces your custom pop-loop

        for (int right = 0; right < n; right++) {
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            mx = max(mx, (int)st.size());
        }

        return mx;
    }
};
