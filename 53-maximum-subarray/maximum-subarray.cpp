class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxsum = INT_MIN, sum=0;

        for(auto i : nums)
        {
            sum += i;
            maxsum= max(maxsum,sum);
            if(sum<0) sum=0;
        }
        return maxsum;
     }
};