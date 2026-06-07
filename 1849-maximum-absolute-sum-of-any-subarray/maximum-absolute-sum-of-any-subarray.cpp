class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int maxi = nums[0], maxcurr = nums[0];
        int mini = nums[0], minicurr = nums[0];

        for(int i =1; i<nums.size(); i++)
        {
            maxcurr = max(nums[i], nums[i]+maxcurr);
            maxi = max(maxi, maxcurr);

            minicurr = min(nums[i], nums[i]+minicurr);
            mini = min(mini, minicurr);
        }
        return max(abs(mini), abs(maxi));
    }
};