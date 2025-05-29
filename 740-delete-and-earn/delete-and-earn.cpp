class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        int max_val = *std::max_element(nums.begin(), nums.end());
        std::vector<int> points(max_val+1, 0);
        for(int num : nums){
            points[num] += num;
        }

        std::vector<int> dp(max_val+1, 0);
        dp[0] = points[0];
        dp[1] = std::max(points[0], points[1]);

        for(int i=2; i<=max_val; ++i){
            dp[i] = std::max(dp[i-1], dp[i-2]+points[i]);
        }

        return dp[max_val];
    }
};