class Solution {
public:
    int sumCounts(vector<int>& nums) {

        int sum =0;

         for(int i =0; i<nums.size(); i++)
         {
            bitset<101> map;
            int count =0;
            for(int j = i; j<nums.size(); j++)
            {
                if(map.test(nums[j]) ==0) ++count;
                map.set(nums[j]);
                sum += count*count;
            }
         }
        return sum;
    }
};