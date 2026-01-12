class Solution {
public:
    void sortColors(vector<int>& nums) {

        int i=0, j= nums.size()-1, k=0;
        while(k<=j)
        {
            if(nums[k] == 1)k++;
            else if(nums[k] == 0)
            {
                swap(nums[k],nums[i]);
                k++;
                i++;
            }
            else
            {
                swap(nums[k],nums[j]);
                j--;
            }
        }   
    }
};