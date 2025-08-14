class Solution {
public:
    int maxScore(string s) {
        int total_ones = 0;
        for (char c : s) {
            if (c == '1')  total_ones++;
        }

        int max_score = 0;
        int left_zeros = 0;
        int right_ones = total_ones;

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                left_zeros++;
            } else {
                right_ones--;
            }
            max_score = max(max_score, left_zeros + right_ones);
        }

        return max_score;
    }
};