class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        int up=1,pre=0,ans=0;
        for(int i =1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]) up++;
            else {
                pre = up;
                up = 1;
            }
            int half = up>>1;
            int m = min(pre,up);
            int candidate = max(half, m);
            if(candidate > ans) ans = candidate;
        }
        return ans;
    }
};