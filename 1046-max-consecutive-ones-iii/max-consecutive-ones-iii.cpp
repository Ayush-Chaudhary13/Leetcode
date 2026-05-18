class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int zero =0, maxi = 0;
        int i =0, j =0;
        int n = nums.size();

        while(j<n)
        {
            if(nums[j] == 0) zero++;

            while(zero >k )
            {
                if(nums[i] == 0) zero--;
                i++;
            }

            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
        
    }
};