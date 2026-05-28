class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];

        for(int i =1; i<n; i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
        }

        for(int i =0; i<n; i++)
        {
            int left =0, right =0;
            if(i!=0)
            {
                left = prefix[i-1];
            }
            right = prefix[n-1] - prefix[i];
            if(left == right)
            {
                return i;
            }
        }
        return -1;
    }
};