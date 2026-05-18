class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int i =0,j=0,n = nums.size();
        int mini = INT_MAX;
        int sum =0;

        while(j<n)
        {
            sum += nums[j];
            while(i<=j && sum >= target)
            {
                int len = j-i+1;
                mini = min(mini,len);
                sum -= nums[i++];    
            } 
            j++; 
        }
        if(mini == INT_MAX) return 0;
        return mini;
    }
};