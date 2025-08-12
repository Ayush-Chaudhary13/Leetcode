class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                vector<int> rem;
                for (int i = 0; i < n; ++i)
                    if (i < l || i > r) rem.push_back(nums[i]);
                bool ok = true;
                for (int i = 1; i < rem.size(); ++i)
                    if (rem[i] <= rem[i-1]) ok = false;
                if (ok) ++res;
            }
        }
        return res;
    }
};