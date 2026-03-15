class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l=0, r=0, mini = INT_MAX;
        int sum =0;

        for(r; r < nums.size(); r++)
        {
            sum += nums[r];

            while(sum >= target)
            {
                int len = r-l+1;
                mini = min(mini,len);
                sum -= nums[l++];
            }
        }
        if(mini == INT_MAX) return 0;
        return mini;
    }
};