class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i =0, zeroes=0,count=0,maxi = 0;

        for(int j=0; j<nums.size(); j++)
        {
            if(nums[j]== 0) zeroes++;
                while(zeroes > k)
                {
                    if(nums[i] == 0) zeroes--;
                    i++;
                }
            count = j-i+1;
            maxi = max(maxi, count);
        }
        return maxi;
    }
};