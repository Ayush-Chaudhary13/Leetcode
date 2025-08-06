class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
   int n=nums.size();
    int maxnum=abs(nums[0]-nums[n-1]);
    for(int i=0;i<n-1;i++){
        maxnum=max(maxnum,abs(nums[i+1]-nums[i]));
    } 
    return maxnum;  
    }
};