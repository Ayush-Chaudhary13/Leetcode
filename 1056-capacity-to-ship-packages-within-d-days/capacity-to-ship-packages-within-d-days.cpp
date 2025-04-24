class Solution {
public:
    bool check(vector<int>& weights, int curr, int days) {
        int count = 1, total = 0;
        for (int weight : weights) {
            if (weight > curr) return false; // Cannot ship this package at all
            if (total + weight > curr) {
                count++;
                total = weight;
                if (count > days) return false;
            } else {
                total += weight;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0, e = 0, mid, ans;
        for (auto x : weights) {
            s = max(s, x);
            e += x;
        }
        ans = e;

        while (s <= e) {
            mid = (s + e) / 2;
            if (check(weights, mid, days)) {
                ans = min(ans, mid);
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};