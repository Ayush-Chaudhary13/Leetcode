class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        for (int a = 0; a + 2 * k <= n; a++) {
            int b = a + k;
            bool valid = true;
            for (int i = 1; i < k; i++) {
                if (nums[a + i] <= nums[a + i - 1] ||
                    nums[b + i] <= nums[b + i - 1]) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                return true;
        }

        return false;
    }
};