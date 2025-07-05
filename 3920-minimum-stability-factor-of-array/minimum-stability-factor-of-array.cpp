class Solution {
public:
    int minStable(vector<int>& nums, int maxC) {
        int n = nums.size();
        int l=0, r=n+1;
        while(l+1 < r) {
            int mid = (l+r)/2;
            if(getCount(nums, n, mid) <= maxC)
                r = mid;
            else
                l = mid;
        }

        return l;
    }

    int getCount(vector<int>& nums, int n, int len) {
        
        int req = 0;
        for(int i=0; i+len-1<n; ) {
            int gcd = nums[i];
            for(int j=i+1; j<i+len && gcd>1; j++) {
                gcd = __gcd(gcd, nums[j]);
            }

            if(gcd > 1) {
                req++;
                i = i+len;
            }
            else {
                i++;
            }
        }

        return req;
    }
};