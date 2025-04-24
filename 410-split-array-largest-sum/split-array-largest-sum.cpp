class Solution {
public:
    bool check(vector<int>&nums, int k, int curr)
    {
        int i= 0, n= nums.size(), count=1, sum=0;

        while(i<n && count<=k)
        {
            if(sum + nums[i] <= curr) sum += nums[i];

            else sum = nums[i], count++;

            i++;
        }

        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {

        int s=0,e=0,mid,ans;

        for(auto x: nums)
        {
            e += x;
            s= max(s,x);
        }
        ans=e;

        while(s<=e)
        {
            mid = s+ (e-s)/2;

            if(check(nums,k,mid))
            {
                ans = min(ans,mid);
                e = mid-1;
            }

            else s = mid+1;
        }
        return ans;
    }
};