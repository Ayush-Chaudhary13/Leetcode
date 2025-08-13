class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {

        long long ans=0;
        int i=0, j=nums.size()-1;

        while(i<=j)
        {
            if(i==j) {
                ans += nums[i];
            }
            else {
                int d = (nums[j] == 0 ) ? 1 : static_cast<int>(log10(nums[j]) +1);
                ans += nums[i]*pow(10,d) + nums[j];
            }
            i++,j--;
        }
       return ans; 
    }
};