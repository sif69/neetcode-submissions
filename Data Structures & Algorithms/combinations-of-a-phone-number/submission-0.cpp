class Solution {
public:
    vector<string> ans;
    // Fix 1: use unordered_map, initialized properly inside class
    unordered_map<char, string> dict = {
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    void Solve(int ind, string& temp, string& digits) {
        // Fix 4: push THEN return, don't clear
        if (ind == digits.size()) {
            ans.push_back(temp);
            return;
        }

        // Fix 3: j declared locally inside Solve
        char key = digits[ind];
        string letters = dict[key];   // all chars for this digit

        // Fix 5: iterate over letters of THIS digit, not ind..size
        for (int i = 0; i < letters.size(); i++) {
            temp.push_back(letters[i]);
            Solve(ind + 1, temp, digits);  // move to next digit
            temp.pop_back();               // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        // Fix 6: empty check
        if (digits.empty()) return {};

        string temp;
        Solve(0, temp, digits);
        return ans;
    }
};