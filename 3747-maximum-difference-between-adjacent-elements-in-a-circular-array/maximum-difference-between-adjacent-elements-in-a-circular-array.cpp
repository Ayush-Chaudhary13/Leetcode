class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
         int maxi = INT_MIN;
        for (int i = 0; i < nums.size()-1; i++) {
            int diff = abs(nums[i+1] - nums[i]);
            maxi = max(diff, maxi);
        }

        int diff2 = abs(nums[nums.size() - 1] - nums[0]);
        maxi = max(diff2, maxi);
        return maxi;
    }
};