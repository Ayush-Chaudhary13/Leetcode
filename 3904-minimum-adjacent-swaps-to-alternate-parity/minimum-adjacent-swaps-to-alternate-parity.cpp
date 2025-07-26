class Solution {
public:
    int solve(vector<int> v) {
        int c = 0;
        for (int i = 0; i < v.size(); i++) {
            c += abs(v[i] - 2 * i);
        }

        return c;
    }
    int minSwaps(vector<int>& nums) {

        vector<int> even, odd;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        }

        int e = even.size();
        int o = odd.size();

        if (abs(e - o) > 1)
            return -1;

        int ans = INT_MAX;

        if (e >= o)
            ans = min(ans, solve(even));
        if (o >= e)
            ans = min(ans, solve(odd));

        return ans;
    }
};