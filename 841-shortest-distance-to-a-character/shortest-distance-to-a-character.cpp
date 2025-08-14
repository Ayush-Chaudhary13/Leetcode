class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(), 0);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c)
                continue;
            int f = INT_MAX;
            for (int j = i; j < s.size(); j++) {
                if (s[j] == c) {
                    f = abs(i - j);
                    break;
                }
            }
            int b = INT_MAX;
            for (int k = i; k >= 0; k--) {
                if (s[k] == c) {
                    b = abs(i - k);
                    break;
                }
            }
            ans[i] = min(f, b);
        }
        return ans;
    }
};