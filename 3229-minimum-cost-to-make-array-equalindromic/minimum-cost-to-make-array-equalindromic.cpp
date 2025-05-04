class Solution {
public:
    bool ispal(long long dec){
        string s=to_string(dec);
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    long long mincost(vector<int>& nums, long long n){
        long long ans=0;
        for(int i:nums){
            ans+=abs(n-i);
        }
        return ans;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long mid=nums[n/2];
        long long dec=mid,inc=mid;
        while(dec>=0&&!ispal(dec)) dec--;
        while(!ispal(inc)) inc++;

        return min(mincost(nums,dec),mincost(nums,inc));
    }
};