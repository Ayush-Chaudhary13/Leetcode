class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        // Remove consecutive duplicates
        vector<int> arr;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i-1])
                arr.push_back(nums[i]);
        }
        // Now check hills and valleys
        for (int i = 1; i < arr.size() - 1; ++i) {
            if ((arr[i] > arr[i-1] && arr[i] > arr[i+1]) ||
                (arr[i] < arr[i-1] && arr[i] < arr[i+1]))
                ans++;
        }
        return ans;
    }
};