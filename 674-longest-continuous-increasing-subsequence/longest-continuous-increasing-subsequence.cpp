class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int l=0, r=1, maxi = 1;

        while(r<nums.size())
        {
            int length =0;
            if(nums[r] > nums[r-1])
            {
                length = r-l+1;
                r++;
            }
            else
            {
                l=r;
                r++;
            }

            maxi = max(length, maxi);
        }
        return maxi;
    }
};