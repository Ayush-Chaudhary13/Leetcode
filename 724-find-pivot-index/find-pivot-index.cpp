class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix(n);

        for(int i =0; i<n; i++)
        {
            if(i == 0) prefix[i] = nums[i];
            else prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i =0; i<n; i++)
        {
            int sum_left = 0;
            if(i!=0) sum_left = prefix[i-1];

            int sum_right = 0;
            if(i != n-1) sum_right = prefix[n-1] - prefix[i];

            if(sum_left == sum_right) return i;
        }

        return -1;
        
    }
};