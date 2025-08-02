class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        long long maxi = INT_MIN;

        for(long long i =0; i<nums.size(); i++)
        {
            for(long long j = i+1; j<nums.size(); j++)
            {
                for(long long k = j+1; k<nums.size(); k++)
                {
                    long long ans = (nums[i] - nums[j]);
                    ans = ans*nums[k];
                    maxi = max(ans,maxi);
                }
            }
        }
        if(maxi<0) return 0;

        return maxi;
    }
};