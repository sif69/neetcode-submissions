class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int mx = 1;

        // Try to make the substring all equal to each character 'A' to 'Z'
        for (char target = 'A'; target <= 'Z'; target++) {
            int left = 0, used = 0;

            for (int right = 0; right < n; right++) {
                if (s[right] != target)
                    used++; // replacement needed

                // If we used too many replacements, shrink window
                while (used > k) {
                    if (s[left] != target)
                        used--;
                    left++;
                }

                mx = max(mx, right - left + 1);
            }
        }

        return mx;
    }
};
