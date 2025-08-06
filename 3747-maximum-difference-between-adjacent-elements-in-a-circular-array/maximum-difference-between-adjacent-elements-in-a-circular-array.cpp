class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int maxi = INT_MIN;

        for(int i =1; i<nums.size(); i++)
        {
            int diff = abs(nums[i]-nums[i-1]);
            maxi = max(diff,maxi);
        }

        int diff2 = abs(nums[nums.size()-1] - nums[0]);
        maxi = max(diff2, maxi);
        return maxi;
    }
};