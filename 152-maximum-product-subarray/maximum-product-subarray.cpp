class Solution {
public:
    int maxProduct(vector<int>& nums) {
    
     int mini = nums[0], maxi = nums[0], ans= nums[0];

        for(int i = 1; i<nums.size(); i++)
        {
            int temp = maxi;
            maxi = max({nums[i], maxi*nums[i], mini*nums[i]});
            mini = min({nums[i], temp*nums[i], mini*nums[i]});

            ans = max(ans, maxi);
        }
return ans;
        
    }
};