class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0; int r = nums.size()-1; 
        vector<int>ans(r + 1);
        
        for(int i = r; i >= 0; i--)
        {
            if(abs(nums[l]) >= abs(nums[r]))
            {
                ans[i] = nums[l] * nums[l];
                l++;
            } 
            else 
            {
                ans[i] = nums[r] * nums[r];
                r--;
            }
        }
        return ans;
    }
};