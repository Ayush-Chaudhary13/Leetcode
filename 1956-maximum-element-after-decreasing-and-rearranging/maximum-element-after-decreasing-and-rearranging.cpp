class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        nums[0] = 1;

        for(int i =1; i<nums.size(); i++)
        {
            nums[i] = min(nums[i], nums[i-1]+1);
        }
       return nums[nums.size()-1];
        
    }
};