class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < n; i++) {
            int id = s[i] - 'a';
            if (first[id] == -1) first[id] = i;
            last[id] = i;
        }

        vector<pair<int,int>> seg;
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1) {
                seg.push_back({first[i], last[i]});
            }
        }

        sort(seg.begin(), seg.end());

        vector<int> ans;

        int st = seg[0].first;
        int en = seg[0].second;

        for (int i = 1; i < seg.size(); i++) {
            if (seg[i].first <= en) {
                en = max(en, seg[i].second);
            } else {
                ans.push_back(en - st + 1);
                st = seg[i].first;
                en = seg[i].second;
            }
        }

        ans.push_back(en - st + 1);
        return ans;
    }
};