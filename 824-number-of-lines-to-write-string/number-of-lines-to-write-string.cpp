class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans = {1, 0};
        for (auto i : s) {
            ans[1] += widths[i - 'a'];
            if (ans[1] > 100) {
                ans[0]++;
                ans[1] = widths[i - 'a'];
            }
        }
        return ans;
    }
};