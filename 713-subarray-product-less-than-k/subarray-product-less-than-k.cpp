class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        long long pdt = 1;
        int i =0;

        for(int j =0; j< nums.size(); j++)
        {
            pdt *= nums[j];
            while(i<j && pdt >= k)
            {
                pdt /= nums[i];
                i++;
            }
            if(pdt < k) ans += j-i+1;
        }
        return ans;
    }
};