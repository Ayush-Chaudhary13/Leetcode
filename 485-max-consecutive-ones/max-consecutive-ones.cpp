class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count =0, maxi= INT_MIN;

        for(int i =0; i<nums.size(); i++)
        {
           if(nums[i] == 1) count ++;
           else
           {
            maxi = max(count, maxi);
            count =0;
           }
        }
        maxi = max(count,maxi);
        return maxi;
    }
};