class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {

        int count = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                bool valid = true;

                for (int k = 1; k < i; k++) {
                    if (nums[k] <= nums[k - 1]) {
                        valid = false;
                        break;
                    }
                }

                for (int k = j + 2; k < n; k++) {
                    if (nums[k] <= nums[k - 1]) {
                        valid = false;
                        break;
                    }
                }

                if (i > 0 && j < n - 1 && nums[i - 1] >= nums[j + 1]) {
                    valid = false;
                }

                if (valid)
                    count++;
            }
        }
        return count;
    }
};