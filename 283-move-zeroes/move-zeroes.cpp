class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        int j = 0, i=0;

        while(j<n)
        {
          if(nums[j] != 0)
          {
            swap(nums[i],nums[j]);
            i++;
            j++;
          }
          else
          {
            j++;
          }

        }
        
    }
};