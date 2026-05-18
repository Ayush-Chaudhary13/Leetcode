class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        long long pdt =1;
        int ans =0;

        int n = nums.size();
        int i =0,j=0;

        while(j<n)
        {
            pdt *= nums[j];
            while(i<j && pdt>=k )
            {
                pdt /=nums[i];
                i++;
            }
            if(pdt<k) ans += j-i+1;
            j++;
        }
return ans;
        
    }
};