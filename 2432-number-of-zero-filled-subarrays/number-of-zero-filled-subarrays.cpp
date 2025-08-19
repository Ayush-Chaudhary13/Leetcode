class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans =0;

        for(int i =0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                long long zero = 0;
                while( i<nums.size() && nums[i] == 0 ) {
                    zero++;
                    i++;
                }
                ans += (zero*(zero+1))/2;
             }
        }
        return ans;
    }
};