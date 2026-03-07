class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start = 0; int end = nums.size()-1; 
        vector<int>ans(end + 1);
        for(int iterator = end; iterator >= 0; iterator--){
            if(abs(nums[start]) >= abs(nums[end])){
                ans[iterator] = nums[start] * nums[start];
                start++;
            } else {
                ans[iterator] = nums[end] * nums[end];
                end--;
            }
        }
        return ans;
    }
};