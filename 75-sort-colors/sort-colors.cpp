class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        int i =0, j = n-1,k=0;

        for(;k<=j;k++)
        {
            if(nums[k] == 1) continue;
            else if(nums[k] == 0)
            {
                swap(nums[i++],nums[k]);
            }
            else 
            {
                swap(nums[k--],nums[j--]);
            }
        }
    }
};